/****************************************************
 * ファイル名　：AnalKeyMatrix.ino
 * 役割　　　　：キーマトリクス分析
 * 作成日　　　：2024.03.05
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
 #include "Common.h"
 #include "SharedFunction.h"

/***** ファイル外-利用グローバル変数 ***************/
/***** ファイル内グローバル変数 ********************/
/***** ファイル内-関数-定義 ************************/
 //static KeyCode_t calcKeyCode(uint8_t key_matrix[NUM_MTRX_OUT_PIN]);
/***** 公開関数 ***********************************************/
/****************************************************
 * 関数名　：analKeyMatrix
 * 機能　　：キーマトリクスの分析
 * 引数　　：[uint8_t] current_matrix[5]
 * 戻り値　：[KeyCode_t] key_code
 * 備考　　：
 ***************************************************/
 KeyCode_t analKeyMatrix(uint8_t current_matrix[NUM_MTRX_OUT_PIN])
{
  static uint8_t previous_matrix[NUM_MTRX_OUT_PIN] = { 0 }; 
  uint8_t changed_matrix[NUM_MTRX_OUT_PIN] = { 0 };
  static KeyCode_t key_code = KC_NULL;
  bool changed = false;
  int i;

    /* 前回と今回のキーマトリクスの状態を比較, 変化あり=true */
    if (memcmp(previous_matrix, current_matrix, sizeof(previous_matrix)) != 0) {changed = true;}
    
    /* 変更があれば処理開始 */
    if (changed) {
      /* 差分(今回新しく押されたキー)の取得 */
      for (i = 0; i < NUM_MTRX_OUT_PIN; i++) {
        changed_matrix[i] = (previous_matrix[i] ^ current_matrix[i]) & current_matrix[i];  
        /* 例) P:00010100 XOR C:00010001 = X:00000101 , X:00000101 and C:00010001 = Z:00000001 */
      }
      /* key_code に変換 */
      key_code = calcKeyCode(changed_matrix);

      /* 過去状態の更新 */
      memcpy( previous_matrix, current_matrix, sizeof(previous_matrix));
    }
  
 #if 0//defined(DEBUG)
  if (changed) {
    Serial.println("current_matrix");
    Serial.println(current_matrix[0], BIN);
    Serial.println(current_matrix[1], BIN);
    Serial.println(current_matrix[2], BIN);
    Serial.println(current_matrix[3], BIN);
    Serial.println(current_matrix[4], BIN);
    /*Serial.println("-----------");
    Serial.println("previous_matrix");
    Serial.println(previous_matrix[0], BIN);
    Serial.println(previous_matrix[1], BIN);
    Serial.println(previous_matrix[2], BIN);
    Serial.println(previous_matrix[3], BIN);
    Serial.println(previous_matrix[4], BIN);
    Serial.println("-----------");
    Serial.println("changed_matrix");
    Serial.println(changed_matrix[0], BIN);
    Serial.println(changed_matrix[1], BIN);
    Serial.println(changed_matrix[2], BIN);
    Serial.println(changed_matrix[3], BIN);
    Serial.println(changed_matrix[4], BIN);*/
    Serial.println("==============");
  }
 #endif
 #if 0//defined(DEBUG)
  if (key_code != KC_NULL) {
    PRINT_DEBUG(key_code);
  }
 #endif
  return(key_code);
}
  


 /***** 非公開関数 ***********************************************/
 /****************************************************
 * 関数名　：calcKeyCode
 * 機能　　：key_matrix をもとに key_codeを取得
 * 引数　　：[uint8_t] key_matrix[5]
 * 戻り値　：[KeyCode_t] key_code
 * 備考　　：
 ***************************************************/
 static KeyCode_t calcKeyCode(uint8_t key_matrix[NUM_MTRX_OUT_PIN])
 {
  /* col と row のキーマップ (key_code マップと同じ並び)
   *     0 1 2 3 4 5
   *     - - - - - - 
   * 0 | a b c d e f
   * 1 | g h i j k l 
   * 2 | m n o p q r 
   * 3 | s t u v w x
   * 4 | y z C L B E
   */
  int row, col;
  KeyCode_t key_code = KC_NULL;
  int key;

  /* 入力信号をもとに key_code として取得 */
  for (row = 0; row < NUM_MTRX_OUT_PIN; row++) {
    if (key_matrix[row] > 0) {
      for (col = 0; col < NUM_MTRX_IN_PIN; col++) {
        if ((key_matrix[row] << col) == 32) {  /* 8bit のうち,使うのは下6bit */
          key = row * 6 + col + 1;  /* = (出力ピン{row}の識別番号 { 0～4 }) * 6 + (入力ピン{col}の識別番号 { 0～5 }) + 1) */
          key_code = (KeyCode_t) key;
        }
      }
    }
  }
  return(key_code);
 }
