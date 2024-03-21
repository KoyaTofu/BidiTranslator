/****************************************************
 * ファイル名　：TransCtlState.ino
 * 役割　　　　：制御状態遷移
 * 作成日　　　：2024.**.**
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
#include "Common.h"

/***** ファイル外-利用グローバル変数 ***************/
/***** ファイル内グローバル変数 ********************/
/***** ファイル内-関数-定義 ************************/
/***** 公開関数 ***********************************************/
/****************************************************
 * 関数名　：transState
 * 機能　　：key_code をもとに ctl_state を変更する
 * 引数　　：[InputState_t] input_state
 * 戻り値　：[CtlState_t] ctl_state
 * 備考　　：
 ***************************************************/
 CtlState_t transCtlState( InputState_t input_state )
{
  /* 制御状態遷移 */
  switch (input_state.key_code) {
    /* クリア(全削除) */
    case KC_Clear: 
      input_state.ctl_state.ope_mode = eCLEAR;
      break;
    /* 言語モード */
    case KC_La:  
      if      (input_state.ctl_state.lang_mode == eENG) { 
        input_state.ctl_state.lang_mode = eJAP; 
      }
      else if (input_state.ctl_state.lang_mode == eJAP) { 
        input_state.ctl_state.lang_mode = eENG; 
      }
      input_state.ctl_state.ope_mode = eCLEAR;
      break;
    /* 一文字削除 */
    case KC_Bs:  
      input_state.ctl_state.ope_mode = eBACK;
      break;
    /* 入力確定-翻訳 */
    case KC_En:  
      input_state.ctl_state.ope_mode = eENTER;
      break;
    /* 例外時は何もしない */
    default:
      break;
  }
 #if 0//defined(DEBUG)
  PRINT_DEBUG( input_state.key_code );
  PRINT_DEBUG( input_state.ctl_state.ope_mode );
  PRINT_DEBUG( input_state.ctl_state.lang_mode );
 #endif
  return( input_state.ctl_state );
}