/****************************************************
 * ファイル名　：EstStr.ino
 * 役割　　　　：入力文字列の予測
 * 作成日　　　：2024.03.05
 ***************************************************/
 /*** 利用ファイルのヘッダ ***/
 #include "Common.h"
 #include "SharedFunction.h"
 #include "TransMap.h"

/***** ファイル外-利用グローバル変数 ***************/
/*
// TransMap
extern char trans_jap[TRANS_NUM][2][TRANS_JAP_LEN];
extern char trans_eng[TRANS_NUM][2][TRANS_ENG_LEN];
*/
/***** ファイル内グローバル変数 ********************/
/***** ファイル内-関数-定義 ************************/
/***** 公開関数 ***********************************************/
/****************************************************
 * 関数名　：estStr
 * 機能　　：入力文字列の予測
 * 引数　　：[char**] est_ptr, [char**] input_ptr, [LangMode_t] lang_mode
 * 戻り値　：なし(ポインタで est_ptr を上書き反映)
 * 備考　　：
 ***************************************************/
 void estStr( char** est_ptr, char** input_ptr, LangMode_t lang_mode )
{
	bool frag = false;
	int fit_cnt = 0;
	int old_cnt = 0;
	int now_index;
  int i;
	char* dst_ptr = NULL;
	char* map_ptr = NULL;
  char* candidate_ptr = NULL;
  /***** malloc 確保と成否確認 ***********************/
	if (ctlCharMalloc(eMAKE, &dst_ptr, STR_LEN)) {
	if (ctlCharMalloc(eMAKE, &map_ptr, STR_LEN)) {
  if (ctlCharMalloc(eMAKE, &candidate_ptr, STR_LEN)) {
		//　比較するためコピー
    strcpy_sf( dst_ptr, *input_ptr, STR_LEN, 0);

		/* 類似の並びを探索 */
		for (now_index = 0; now_index < TRANS_NUM; now_index++) {
			fit_cnt = 0;
      /* 日本語-入力時 */
			if (lang_mode == eJAP) {  
				for (i = 0; i < (int)strlen(dst_ptr); i++) {
          /* Flash メモリから対象を取得 */
          strcpy_P(map_ptr, (char *)pgm_read_word( &(trans_map[now_index][1]) ));
          /* 1文字ずつ比較 */
					if (*(dst_ptr + i) == *(map_ptr + i)) {
						fit_cnt += 1;
						frag = true;
					}
					else { break; }
        }
			}
      /* 英語-入力時 */
			else {  
				for (i = 0; i < (int)strlen(dst_ptr); i++) {
          /* Flash メモリから対象を取得 */
          strcpy_P(map_ptr, (char *)pgm_read_word( &(trans_map[now_index][0]) ));
					/* 1文字ずつ比較 */
					if (*(dst_ptr + i) == *(map_ptr + i)) {
						fit_cnt += 1;
						frag = true;	
					}
					else { break; }
				}
			}
      /* 前回比較より近似していれば第一候補とする */
      if (fit_cnt >= old_cnt) {
        strcpy_sf( candidate_ptr, map_ptr, STR_LEN, 0);
        old_cnt = fit_cnt;
      }
		}
		/* 類似探索の該当ありなら反映 */
		if (frag) {
      strcpy_sf( *est_ptr, candidate_ptr, STR_LEN, 0);
		}
    /* malloc free */
    ctlCharMalloc(eFREE, &candidate_ptr, STR_LEN);
		ctlCharMalloc(eFREE, &map_ptr, STR_LEN);
		ctlCharMalloc(eFREE, &dst_ptr, STR_LEN);
	
	  /* malloc 確保失敗 */
  } else { PRINT_ERROR(candidate_ptr); }
	} else { PRINT_ERROR(map_ptr); }
	} else { PRINT_ERROR(dst_ptr); }
	
}
