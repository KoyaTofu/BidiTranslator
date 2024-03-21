/****************************************************
 * ファイル名　：GenrStr.ino
 * 役割　　　　：文字列生成
 * 作成日　　　：2024.03.05
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
 #include "Common.h"
 #include "RomanMap.h"

/***** ファイル外-利用グローバル変数 ***************/
 /* Roman.h
 extern char alph[27];  // アルファベット
 extern int alph_site[26];     // roman_map 中で各アルファベットが始まる位置
 extern const char* const roman_map[ROMAN_NUM][2];
 */
/***** ファイル内グローバル変数 ********************/
/***** ファイル内-関数-定義 ************************/
 void cnvtRoman(char** input_ptr);
/***** 公開関数 ***********************************************/
/****************************************************
 * 関数名　：genrStr
 * 機能　　：ascii をもとに文字列の生成
 * 引数　　：[char**] input_ptr, [char] ascii, [LangMode_t] lang_mode
 * 戻り値　：なし(ポインタで input_ptr を上書き反映)
 * 備考　　：
 ***************************************************/
void generStr(char** input_ptr, char ascii, LangMode_t lang_mode)
{
  char ascii_str[2];
  ascii_str[0] = ascii; ascii_str[1] = '\0';

  /* 文字列 末尾に連結(追加)　オーバーフローは許さない */
  strcpy_sf(*input_ptr, ascii_str, STR_LEN, strlen(*input_ptr));

  /* 日本語入力モードならローマ字変換 */
  if (lang_mode == eJAP) {
    cnvtRoman(input_ptr);
  }
 #if 0//defined(DEBUG)
  Serial.println(*input_ptr);
 #endif
  return;
}

/***** 非公開関数 ***********************************************/
/****************************************************
 * 関数名　：cnvtRoman
 * 機能　　：input_ptr をもとにローマ字変換
 * 引数　　：[char**] input_ptr
 * 戻り値　：なし(ポインタで input_ptr を上書き反映)
 * 備考　　：
 ***************************************************/
void cnvtRoman(char** input_ptr)
{
  int alph_head = 0 , map_index;
  int p_h, s_i; 
  char alph_str[STR_LEN];
  int i;

  /* input_ptr 中のアルファベット先頭位置を調べる(半角カナが前にあるなら飛ばす) */
  while (*(*input_ptr + alph_head) < 0x61 || 0x7a < *(*input_ptr + alph_head)) {
    alph_head += 1;
  }

  p_h = alph_head;
  s_i = 0;
  /* アルファベット部分のみ抜き出す */
  while ((*(*input_ptr + p_h) != '\0') || (p_h <= STR_LEN) ) {
    alph_str[s_i] = *(*input_ptr + p_h);
    s_i += 1;
    p_h += 1;
  } alph_str[s_i] = '\0';
  char* akph_ptr = alph_str;

  /* ローマ字に該当するか否か判定 */
  for (i = 0; i < 26; i++) {
    if (akph_ptr[0] == alph[i]) {  /* 先頭アルファベット a~z 判定 */
      map_index = alph_site[i]; /* 処理の効率化 */
      while (map_index <= ROMAN_NUM) {
        /* ローマ字の特定 */
        if (cmpMap( &akph_ptr, eROMAN, map_index)) {
          /* 該当するローマ字が特定されたら置き換え-反映 */
          cpyMap(input_ptr, alph_head, eROMAN, map_index);
          break;
        }
        map_index += 1;
      }
    }
  }
}