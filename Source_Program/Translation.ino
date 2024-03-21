/****************************************************
 * ファイル名　：ManageTrans.ino
 * 役割　　　　：双方向翻訳
 * 作成日　　　：2024.03.05
 ***************************************************/

 /*** 利用ファイルのヘッダ ***/
#include "Common.h"
#include "TransMap.h"

/*** 自ファイルのヘッダ ***/
/***** ファイル外-利用グローバル変数 ***************/
/* TransMap.h
const char* const trans_map[TRANS_NUM][2] PROGMEM;
*/
/***** ファイル内グローバル変数 ********************/
/***** ファイル内-関数-定義 ************************/
/***** 公開関数 ***********************************************/
/****************************************************
 * 関数名　：translation
 * 機能　　：翻訳
 * 引数　　：[char**] trans_ptr, [char**] input_ptr, [LangMode_t] lang_mode
 * 戻り値　：なし(ポインタで trans_ptr を上書き反映)
 * 備考　　：
 ***************************************************/
void translation(char** trans_ptr, char** input_ptr, LangMode_t lang_mode)
{
	int map_index;

	// 該当するものを検索
	for (map_index = 0; map_index < TRANS_NUM; map_index++) {
    /* 日本語入力,英語出力 (jap → eng) */
		if (lang_mode == eJAP) {  
      /* 翻訳リストから該当の文字列を特定 */
      if (cmpMap( input_ptr, eTRANS_JAP, map_index)) {
        /* 該当する文字列が特定されたら置き換え-反映 */
        cpyMap( trans_ptr, 0, eTRANS_ENG, map_index);
				break;
			}
		}
    /* 英語入力,日本語出力 (eng → jap) */
		else { 
      /* 翻訳リストから該当の文字列を特定 */
      if (cmpMap( input_ptr, eTRANS_ENG, map_index)) {
        /* 該当する文字列が特定されたら置き換え-反映 */
        cpyMap( trans_ptr, 0, eTRANS_JAP, map_index);
				break;
			}
		}
	}
	return;
}

