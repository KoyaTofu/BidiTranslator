
#pragma once
/****************************************************
 * ファイル名　：SharedFunction.h　
 * 役割　　　　：共用関数置き場
 * 作成日　　　：2024.03.05
 ***************************************************/
 /* malloc 操作モード */
 typedef enum { eMAKE, eFREE } CtlMalloc_t;

 /* 変換マップ選択用 */
 typedef enum { eROMAN, eTRANS_ENG, eTRANS_JAP, eEST_ENG, eEST_JAP } ConvertMap_t;
 
/****************************************************
 * 公開関数       extern宣言
 ***************************************************/
 /* ms 待つ */
 extern void wait( int ms); 

 /* malloc に関する操作 */
 extern bool ctlCharMalloc( CtlMalloc_t ctl_malloc, char** str_ptr, size_t str_size);

 /* 変換マップと文字列比較 */
 extern bool cmpMap( char** dst_str, ConvertMap_t convert_map, int map_index);

 /* 変換マップからの文字列コピー */
 extern void cpyMap( char** dst_str, int dst_index, ConvertMap_t convert_map, int map_index);

 /* 文字列置き換えコピー(シングルポインタでなければならない) */
 extern void strcpy_sf(char* dst, char* src, size_t dst_size, int first_index);
