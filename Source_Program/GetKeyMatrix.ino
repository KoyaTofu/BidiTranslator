/****************************************************
 * ファイル名　：GetKeyMatrix.ino
 * 役割　　　　：キーマトリクスの取得
 * 作成日　　　：2024.03.05
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
#include "Common.h"

/***** ファイル外-利用グローバル変数 ***************/
/***** ファイル外-利用関数-宣言 ********************/
/***** ファイル内グローバル変数 ********************/
/***** ファイル内-関数-宣言 ************************/
 static bool debounce(int col);
/***** 公開関数 ***********************************************/
/****************************************************
 * 関数名　：getKeyMatrix
 * 機能　　：キーマトリクスの取得
 * 引数　　：[uint8_t] key_matrix[5] (0|1 でON,OFF を表現)
 * 　　　　：[int]     row           (out_pin 0~4 の範囲)
 * 戻り値　：なし(ポインタで key_matrix[5] を上書き反映)
 * 備考　　：最小処理時間 30ms
 ***************************************************/
 void getKeyMatrix(uint8_t key_matrix[NUM_MTRX_OUT_PIN], int row)
{
  int col;
  /* 1列(1col)ずつ状態確認,反映 */
  for (col = 0; col < NUM_MTRX_IN_PIN; col++) {
    /* 0B-0,0,o,o,o,o,o,o の形で状態整理 */
    key_matrix[row] <<= 1;
    
    /* ON=1 | OFF=0 */
    if (debounce(col)) { key_matrix[row] |= 0x1; }
    else               { key_matrix[row] |= 0x0; }

    /* 下 6bitのみ 1 を許す */
    key_matrix[row] &= 0x3f;
  }
 #if 0//defined(DEBUG)
  if (debounce(0) || debounce(1) || debounce(2) || debounce(3) || debounce(4) || debounce(5)) {
    Serial.println(key_matrix[0], BIN);
    Serial.println(key_matrix[1], BIN);
    Serial.println(key_matrix[2], BIN);
    Serial.println(key_matrix[3], BIN);
    Serial.println(key_matrix[4], BIN);
    Serial.println("-----------");
  }
 #endif
}

/***** 非公開関数 ***********************************************/
/****************************************************
 * 関数名　：debounce
 * 機能　　：デバウンス対策
 * 引数　　：[int]  col  (調査対象 pin)
 * 戻り値　：[bool] frag (ON | OFF)
 * 備考　　：
 ***************************************************/
 static bool debounce(int col)
{
  bool frag = OFF;
  /* 入力設定(col) pin の読み取り */
  if (digitalRead( key_input_pin[col] ) == ON ) {
    wait(5);  /* デバウンス対策 */
    if (digitalRead( key_input_pin[col] ) == ON ) {
      frag = ON;
    }
  }
  return(frag);
}