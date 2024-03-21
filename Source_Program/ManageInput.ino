/****************************************************
 * ファイル名　：ManageInput.ino
 * 役割　　　　：入力管理
 * 作成日　　　：2024.03.05
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
#include "Common.h"

/***** ファイル外-利用グローバル変数 ***************/
/***** ファイル内グローバル変数 ********************/
/***** ファイル内-関数-定義 ************************/
static KeyCode_t analKeyCode( KeyCode_t);
static KeyCode_t comboEvent( KeyCode_t , KeyCode_t);
/***** 公開関数 ***********************************************/
/****************************************************
 * 関数名　：manageInput
 * 機能　　：入力状態に応じた処理
 * 引数　　：[InputState_t] input_state
 * 戻り値　：[InputState_t] input_state
 * 備考　　：
 ***************************************************/
InputState_t manageInput(InputState_t input_state)
{
  /* 入力分析 */
  /* キー入力情報取得 */
  input_state.key_code = analKeyMatrix(input_state.current_matrix);

  /* 時系列を考慮に入れて入力判定 */
  input_state.key_code = analKeyCode( input_state.key_code );
 
 /***** key_code 処理 *******************************/
  /* key_code がアルファベットキーならばasciiとして取得 */
  if (KC_a <= input_state.key_code && input_state.key_code <= KC_z) {
    input_state.ascii = 96 + input_state.key_code;
    input_state.ctl_state.ope_mode = eINPUT;
  } 
  /* key_code が制御キーならば制御状態遷移 */
  else if ((KC_La <= input_state.key_code && input_state.key_code <= KC_En) || input_state.key_code == KC_Clear ) {
    input_state.ctl_state = transCtlState( input_state );
  }
  /* key_code が comboEvent に該当する場合 */
  else if (31 <= input_state.key_code) {
    if      (input_state.key_code == KC_Spc)   { input_state.ascii = 0x20; }  /* 空白入力 */
    else if (input_state.key_code == KC_Point) { input_state.ascii = 0xA5; } /* 「･」入力 */
  }

 #if 0//defined(DEBUG)
  if (input_state.key_code != KC_NULL) {
    PRINT_DEBUG( input_state.key_code );
  }
 #endif
  return(input_state);
}

/***** 非公開関数 ***********************************************/
/****************************************************
 * 関数名　：analKeyCode
 * 機能　　：前後の入力状態をもとに入力内容を判定
 * 引数　　：[KeyCode_t] now_key
 * 戻り値　：[KeyCode_t] now_key
 * 備考　　：本来は「key_code」だが見やすいようにここだけ名前変更「now_key」
 *  NULL化させる理由があればNULLを代入する,なければそのまま
 ***************************************************/
static KeyCode_t analKeyCode(KeyCode_t now_key)
{
  static KeyCode_t old_key = KC_NULL;
  static unsigned int bef_time;
         unsigned int now_time;
  static bool key_hold = false;

  /* スイッチが押される場合 [OFF → ON] */
  if (old_key == KC_NULL && now_key != KC_NULL) {
    bef_time = millis();
    old_key = now_key;  
  }
  /* スイッチ長押し [ON → ON] */
  else if (old_key != KC_NULL && now_key != KC_NULL) {
    /* 異なるキーが押される */
    if (now_key != old_key) {
      
      /* コンボイベント処理 */
      now_key = comboEvent( old_key, now_key);
    
      old_key = now_key;
      
      bef_time = millis();
    }
    /* 同じキーが長押しされる場合 [now_key == old_key] */
    else { 
      now_time = millis();

      /** 長押しモードOFFで且つ,500 ms 以上長押しされているならば
        * 意図的,長押し入力の初回と判断 */
      if (key_hold == false && (now_time - bef_time >= 500) ) {
        key_hold = true;
        bef_time = now_time;
        old_key = now_key; 
      }
      /** 長押しモードONで且つ,100ms以上長押しならば
        * 意図的,長押し入力の継続と判断 */
      else if (key_hold == true && (now_time - bef_time >= 100) ) {
        bef_time = now_time;
        old_key = now_key;  
      }
      /* 上記どちらにも該当しない場合は,入力としないが,ON状態は維持 */
      else {
        old_key = now_key;  
        now_key = KC_NULL; 
      }
    }
  }
  /* 誤作動 [ON → OFF] [OFF → OFF] */
  else {
    now_key = KC_NULL;  /* NULL 化 */
    key_hold = false;   /* 長押しモードOFF */
    old_key = now_key;  /* old_key 情報更新 */
  }
 #if 0//defined(DEBUG)
  if (now_key != KC_NULL) {
    PRINT_DEBUG( now_key );
  }
 #endif
  return(now_key);
}

/****************************************************
 * 関数名　：comboEvent
 * 機能　　：複合操作(複数キーの同時連続押しによる操作)
 * 引数　　：[KeyCode_t] old_key, [KeyCode_t] now_key
 * 戻り値　：[KeyCode_t] now_key
 * 備考　　：
 ***************************************************/
static KeyCode_t comboEvent( KeyCode_t old_key, KeyCode_t now_key)
{
  /* KC_Ctl とa の複合操作 = 空白 */
  if (old_key == KC_Ctrl && now_key == KC_a) {
    now_key = KC_Spc;
  }
  /* KC_Ctl とm の複合操作 = '・' */
  else if (old_key == KC_Ctrl && now_key == KC_m) {
    now_key = KC_Point;
  }
  /* KC_Ctl とKC_Bs の複合操作 = クリア */
  else if (old_key == KC_Ctrl && now_key == KC_Bs) {
    now_key = KC_Clear;
  }
  wait(100); /* 少し待つ */
  return(now_key);
}