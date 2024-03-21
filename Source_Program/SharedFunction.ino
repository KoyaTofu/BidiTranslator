/****************************************************
 * ファイル名　：SharedFunction.ino
 * 役割　　　　：共用関数置き場
 * 作成日　　　：2024.**.**
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
 #include "Common.h"
 #include "RomanMap.h"
 #include "TransMap.h"
 #include "SharedFunction.h"
/***** ファイル外-利用グローバル変数 ***************/
/***** ファイル外-利用関数-宣言 ********************/
/***** ファイル内グローバル変数 ********************/
/***** ファイル内-関数-宣言 ************************/
 void wait( int ms);
 bool ctlCharMalloc( CtlMalloc_t ctl_malloc, char** str_ptr, size_t str_size);
 bool cmpMap( char** dst_str, ConvertMap_t convert_map, int map_index);
 void cpyMap( char** dst_str, int dst_index, ConvertMap_t convert_map, int map_index);
 void strcpy_sf(char* dst, char* src, size_t dst_size, int first_index);
/***** 公開関数 ***********************************************/
/****************************************************
 * 関数名　：wait
 * 機能　　：引数(ミリ秒)待つ
 * 引数　　：[int] ms
 * 戻り値　：なし
 * 備考　　：
 ***************************************************/
 void wait( int ms)
{
  unsigned int time_now;
  unsigned int time_before;

  time_before = millis();

  while(true) {
    time_now = millis();

    if (time_now - time_before >= (unsigned int)ms) break;
  }
  return;
}
/****************************************************
 * 関数名　：ctlMalloc
 * 機能　　：malloc 管理
 * 引数　　：[CtlMalloc_t] ctl_malloc (操作内容 {eMAKE,eFREE})
 * 　　　　：[char**]      str_ptr    (操作対象文字列へのポインタ)
 * 戻り値　：[bool]        frag       (正常処理完了 = true)
 * 備考　　：
 ***************************************************/
 bool ctlCharMalloc( CtlMalloc_t ctl_malloc, char** str_ptr, size_t str_size)
{
	bool frag = true;
	/***** malloc 生成 *********************************/
	if (ctl_malloc == eMAKE) {
		if (*str_ptr == NULL) {  /* 二重 malloc 防止 */
			*str_ptr = (char*)malloc(sizeof(char[str_size]));
			/*** ヒープ領域 確保ミス ***/
			if (*str_ptr == NULL) {
				Serial.println("ERROR: MISS TO GET MALLOC. ");
        frag = false;
			}
			/*** ヒープ領域 正常確保 ***/
			else {
				/* 文字列の初期化 */
				memset(*str_ptr, '\0', str_size);
        frag = true;
			}
		}
  }
  /***** malloc 解放 *********************************/
  else {  /* eFREE */
    free(*str_ptr);
    *str_ptr = NULL;
    frag = true;
  }
	return(frag);
} 
/****************************************************
 * 関数名　：cmpStr
 * 機能　　：変換マップと文字列比較
 * 引数　　：[char**]   dst_str     (比較したい文字列のポインタ)
 * 　　　　：[CmpMap_t] convert_map (比較対象の変換マップ識別記号 {eROMAN, eTRANS_JAP, eTRANS_ENG, eEST})
 * 　　　　：[int]      map_index   (変換マップ中の要素番号)
 * 戻り値　：[bool]     frag        (同じ = true)
 * 備考　　：strcmp と 各種変換 map の合体
 ***************************************************/
 bool cmpMap( char** dst_str, ConvertMap_t convert_map, int map_index)
{
  bool frag = false;
  char* map_ptr = NULL;
  /***** malloc 確保と成否確認 ***********************/
  if (ctlCharMalloc(eMAKE, &map_ptr, STR_LEN)) {
    switch (convert_map) {
      /* 対象のローマ字変換マップを flash メモリから取得 */
      case eROMAN:
        strcpy_P(map_ptr, (char *)pgm_read_word( &(roman_map[map_index][0]) ));
        break;
      
      case eTRANS_ENG: /* (ENG → JAP) ENG側-翻訳変換マップとの比較 */
      case eEST_ENG:   /* (ENG → JAP) ENG側-文字列予測時の比較 */
        strcpy_P(map_ptr, (char *)pgm_read_word( &(trans_map[map_index][0]) ));
        break;

      case eTRANS_JAP:  /* (JAP → ENG) JAP側-翻訳変換マップとの比較 */
      case eEST_JAP:  /* (JAP → ENG) JAP側-文字列予測時の比較 */
        strcpy_P(map_ptr, (char *)pgm_read_word( &(trans_map[map_index][1]) ));
        break;
      
      default:
        break;
    }
    /* ローマ字変換マップとの比較 */
    if (strcmp( *dst_str, map_ptr) == 0) {frag = true;}
    /***** malloc 解放 *********************************/
    ctlCharMalloc(eFREE, &map_ptr, STR_LEN);

  /***** malloc 確保失敗 *****************************/ 
  /* 異常通知 */
  } else { PRINT_ERROR(map_ptr); }
  return(frag);
}
/****************************************************
 * 関数名　：cpyMap
 * 機能　　：変換マップからの文字列コピー
 * 引数　　：[char**]   dst_str     (コピー先文字列のポインタ)
 * 　　　　：[int]      dst_index   (コピー開始位置)
 * 　　　　：[CmpMap_t] convert_map (コピー対象の変換マップ識別記号 {eROMAN, eTRANS_JAP, eTRANS_ENG, eEST})
 * 　　　　：[int]      map_index   (変換マップ中の要素番号)
 * 戻り値　：なし(裏側で反映される)
 * 備考　　：strcpy と 各種変換 map の合体
 ***************************************************/
 void cpyMap( char** dst_str, int dst_index, ConvertMap_t convert_map, int map_index)
{
  char* map_ptr = NULL;  /* convert_map 用 */

  /***** malloc 確保と成否確認 ***********************/
  if (ctlCharMalloc(eMAKE, &map_ptr, STR_LEN)) {
    
    /***** コピー処理 **********************************/
    /* Flash メモリ中の該当文字列を取得 */
    switch(convert_map) {

      /* ローマ字変換マップからカナ文字をコピー */
      case eROMAN:
        strcpy_P(map_ptr, (char *)pgm_read_word( &(roman_map[map_index][1]) ));
        break;

      /* 日英-翻訳マップからカナ文字をコピー */
      case eTRANS_ENG:
      case eEST_ENG:
        strcpy_P(map_ptr, (char *)pgm_read_word( &(trans_map[map_index][0]) ));
        break;

      /* 日英-翻訳マップから英文字をコピー */
      case eTRANS_JAP:
      case eEST_JAP:
        strcpy_P(map_ptr, (char *)pgm_read_word( &(trans_map[map_index][1]) ));
        break;

      default:
       break;
    }
    
    /* [置き換えコピー] (既存の半角カナ文字があれば,後ろに新規を付ける) */
    strcpy_sf(*dst_str, map_ptr, STR_LEN, dst_index);

    /***** malloc 解放 *********************************/
    ctlCharMalloc(eFREE, &map_ptr, STR_LEN);

  /***** malloc 確保失敗 *****************************/ 
  /* 異常通知 */
  } else { PRINT_ERROR(map_ptr); }
}
/****************************************************
 * 関数名　：strcpy_sf
 * 機能　　：src を dst に, first_index から dst_size まで置き換えコピー(最後は'\0')
 * 引数　　：[char*] dst         (コピー先文字列のポインタ)
 * 　　　　：[char*] src         (コピー元文字列のポインタ)
 * 　　　　：[int]   dst_size    (コピー先文字列のメモリサイズ)
 * 　　　　：[int]   first_index (コピー開始位置,0 ~ )
 * 戻り値　：なし
 * 備考　　：arduino では MS の strcpy_s が使えないから自作
 ***************************************************/
 void strcpy_sf(char* dst, char* src, size_t dst_size, int first_index)
{
	/* コピー先が未定義ならエラー */
	if (dst == NULL) {
    Serial.println("ERROR: [strcpy_sf] コピー先 = NULL");
    exit(1); 
  }

	/* コピー元が未定義なら何もしないで終了 */
	if (src == NULL) { return; }

  /* dst_size <= first_index ならエラー */
  if (dst_size <= (size_t)first_index ) {
    Serial.println("ERROR: [strcpy_sf] サイズ指定エラー");
    exit(1); 
  }
  /* コピー */
	memcpy(dst + first_index, src, sizeof(char) * ( dst_size - 1 - first_index ));
	/* 最後尾にナル文字格納 */
	*(dst + (dst_size - 1)) = '\0';
}