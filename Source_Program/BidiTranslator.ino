/****************************************************
 * ファイル名　：[BOSS]TwoWayTranslator.ino
 * 役割　　　　：全ファイル総括boss(setup,loop)
 * 作成日　　　：2024.02.04
 * 使用メモリ領域：フラッシュメモリ17.912kByte, RAM 1.054kByte
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
 #include "Common.h"
 #include "SharedFunction.h"
 
/***** ファイル内グローバル変数 ********************/
 /* 入力情報 */
  InputState_t input_state;

 /* 出力情報変数 初期化 */
  char* input_ptr  = NULL;  
  char* trans_ptr  = NULL;
  char* est_ptr    = NULL;

/****************************************************
 * setup
 ***************************************************/
 void setup() 
{
  int i;
  /* キーマトリクス(OutPut)用pin 設定 */
  for( i = 0; i < 5; i++) {
    pinMode( key_output_pin[i], OUTPUT);
  }
  /* キーマトリクス(InPut)用pin 設定 */
  for( i = 0; i < 6; i++) {
    pinMode( key_input_pin[i], INPUT);
  }
  /* 入力情報変数 初期化 */
  input_state.ctl_state.lang_mode = eENG;
  input_state.ctl_state.ope_mode  = eINPUT;
  input_state.ascii               = '\0';
  input_state.key_code            = KC_NULL;

 /***** malloc 確保と成否確認 (基本常に確保しておく) ***********************/
  if (ctlCharMalloc(eMAKE, &input_ptr, STR_LEN) == false) { PRINT_ERROR(&input_ptr); exit(1); }
  if (ctlCharMalloc(eMAKE, &trans_ptr, STR_LEN) == false) { PRINT_ERROR(&trans_ptr); exit(1); }
  if (ctlCharMalloc(eMAKE, &est_ptr,   STR_LEN) == false) { PRINT_ERROR(&est_ptr);   exit(1); }

 #if defined(DEBUG)
  /* デバック用　シリアルポートを有効化 */
  Serial.begin(9600);
  Serial.println("start!!");
 #endif
}

/****************************************************
 * loop
 ***************************************************/
 void loop() 
{
  static unsigned int bef_time = millis();
         unsigned int now_time;
  static int out_pin = 0;
  static int prv_pin = 0;
  input_state.key_code = KC_NULL;

 /***** HIGH出力Pin操作-入力管理 *******************************/
 /***************************************************/
  now_time = millis();
  /* 10ms 毎に処理 */  /* 450ms 毎になっている なんで？ */
  if ((now_time - bef_time) >= 10) {
    bef_time = now_time;
     
    /* 各ピンのOUTPUT 切り替え */
    digitalWrite( key_output_pin[out_pin], HIGH);
    digitalWrite( key_output_pin[prv_pin], LOW);
    prv_pin = out_pin;

    /* 現在キーマトリクスの取得 */
    getKeyMatrix( input_state.current_matrix, out_pin);

    /* 対象 pin を次へ */
    out_pin += 1;

    /* 一周したら読み取り */
    if (out_pin == 5) {
      input_state = manageInput(input_state);
      out_pin = 0;
    }
  }
 /***** 文字列-操作・管理 **************************************/
 /***************************************************/
  // 入力があれば文字列を処理
  if (input_state.key_code != KC_NULL)
  {
    // 文字列操作
    operateStr( input_state, &input_ptr, &trans_ptr, &est_ptr );
    /* input_ptr = ヒープ領域該当文字列, *input_ptr = ヒープ領域該当文字列の先頭文字 */
    /* &(input_ptr) = ポインタ自体のアドレス, &(*input_ptr) = ヒープ領域該当文字列の先頭アドレス */
  }

 /***** LCD 表示処理 **************************************/
 /***************************************************/
  displayLcd( &input_ptr, &est_ptr, &trans_ptr, input_state.ctl_state.lang_mode);

 #if 0//defined(DEBUG)
  char* src = "test";
  strcpy_sf(disp_state.input_ptr, src, STR_LEN, 0);
  Serial.println((disp_state.input_ptr));
  Serial.println((*(disp_state.input_ptr+0)));
  Serial.println((*(disp_state.input_ptr+1)));
  Serial.println("----");
 #endif
}