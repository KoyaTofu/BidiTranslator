
#pragma once
/****************************************************
 * ファイル名　：RomanMap.h　
 * 役割　　　　：ローマ字変換用
 * 作成日　　　：2024.**.**
 ***************************************************/
// #define ROMAN_LEN 10
#define ROMAN_NUM 292

/****************************************************
 * グローバル変数 extern宣言
 ***************************************************/
 /* アルファベットa~z */
 extern char alph[27];

 /* roman_map 中において頭文字が a~z の場所 */
 extern int alph_site[26];

 /* ローマ字変換マップ */ 
 extern const char* const roman_map[ROMAN_NUM][2] PROGMEM;