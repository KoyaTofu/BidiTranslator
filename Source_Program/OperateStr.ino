/****************************************************
 * ファイル名　：OperateStr.ino
 * 役割　　　　：文字列を操作
 * 作成日　　　：2024.**.**
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
 #include "Common.h"

/***** ファイル外-利用グローバル変数 ***************/
/*
  * 入力状態 *
  input_state.ctl_state.lang_mode;
  input_state.ctl_state.ope_mode;
  input_state.ascii;
  input_state.input_ptr;
  
  * 表示状態 *
  disp_state.input_ptr;
  disp_state.trans_ptr;
  disp_state.est_ptr;
*/
/***** ファイル内グローバル変数 ********************/
/***** ファイル内-関数-定義 ************************/
/***** 公開関数 ***********************************************/
/****************************************************
 * 関数名　：operateStr
 * 機能　　：文字列の操作
 * 引数　　：[InputState_t] input_state (入力状態)
 * 　　　　：[char**] input_ptr (LCD 表示用 入力値) 
 * 　　　　：[char**] tarns_ptr (LCD 表示用 翻訳値)
 * 　　　　：[char**] est_ptr   (LCD 表示用 予測値)
 * 戻り値　：なし(裏側で変更が反映される)
 * 備考　　：
 ***************************************************/
void operateStr( InputState_t input_state, char** input_ptr, char** trans_ptr, char** est_ptr )
{
  int input_len = 0;

 /***** 文字列-操作-処理 *****************************/
 #if 0//defined(DEBUG)
      if      (input_state.ctl_state.lang_mode == eENG) { PRINT_DEBUG("英語入力モード"); }
      else if (input_state.ctl_state.lang_mode == eJAP) { PRINT_DEBUG("日本語入力モード"); }
 #endif

  switch (input_state.ctl_state.ope_mode) {
    /* 文字列 全削除(文字列の初期化) */
    case eCLEAR:  
			memset(*input_ptr, '\0', STR_LEN);
      memset(*trans_ptr, '\0', STR_LEN);
      memset(*est_ptr, '\0', STR_LEN);
  #if 0//defined(DEBUG)
    PRINT_DEBUG(" クリア(全削除) : ");
    PRINT_DEBUG(*input_ptr);
  #endif
      break;
    
    /* 最後尾 1文字 削除 */
    case eBACK:  
      input_len = (int)strlen(*input_ptr);
      if (input_len != 0) {
        /* 文字列があれば最後尾に'\0'を代入 */
        *(*input_ptr + (input_len - 1)) = '\0'; 
      }
  #if 0//defined(DEBUG)
    Serial.print(" 一文字削除 : ");
          Serial.println(input_ptr);
	#endif
    	break;  
    
    /* 入力確定-双方向翻訳 */
    case eENTER: 
      strcpy_sf(*input_ptr, *est_ptr, STR_LEN, 0);
      /* 翻訳-処理 */
      translation( trans_ptr, input_ptr, input_state.ctl_state.lang_mode);

  #if 0//defined(DEBUG)
    PRINT_DEBUG("入力文字列確定、翻訳します");
    Serial.print(" 翻訳前 : ");
          Serial.println(input_ptr);
		Serial.print(" 翻訳後 : ");
          Serial.println(trans_ptr);
  #endif
      break;

    /* 文字列生成 */
    default:
     if (input_state.key_code != KC_Ctrl ) {
      /* アルファベットを文字列として読み取り */
      generStr( input_ptr, input_state.ascii, input_state.ctl_state.lang_mode );

      /* 入力文字列予測 */
      estStr( est_ptr, input_ptr, input_state.ctl_state.lang_mode );
     }
      break;
  }
  #if defined(DEBUG)
    Serial.print("入力文字列 : ");  
          Serial.println(*input_ptr);
    Serial.print("予測文字列 : ");
          Serial.println(*est_ptr);
    Serial.print(" 翻訳後 : ");
          Serial.println(*trans_ptr);
  #endif
}