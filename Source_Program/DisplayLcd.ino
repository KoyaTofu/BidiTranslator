/****************************************************
 * ファイル名　：Display_GenerStr.ino
 * 役割　　　　：LCD 表示処理
 * 作成日　　　：2024.03.05
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
#include "Common.h"

/*** 自ファイルのヘッダ ***/
/***** ファイル外-利用グローバル変数 ***************/
/***** ファイル外-利用関数-宣言 ********************/
/***** ファイル内グローバル変数 ********************/
/***** ファイル内-関数-宣言 ************************/
  DisplayMode_t generText( char** text_upper, char** text_lower, char** input_ptr, char** est_ptr, char** trans_ptr, LangMode_t lang_mode);
/***** 公開関数 ***********************************************/
/****************************************************
 * 関数名　：displayLcd
 * 機能　　：LCD に表示指示
 * 引数　　：[char**] input_ptr, [char**] est_ptr, [char**] trans_ptr, [LangMode_t] lang_mode
 * 戻り値　：なし
 * 備考　　：
 ***************************************************/
 void displayLcd( char** input_ptr, char** est_ptr, char** trans_ptr, LangMode_t lang_mode)
{
  DisplayMode_t display_mode = eENG_ENG;
  char* text_upper = NULL;
  char* text_lower = NULL;
  /***** malloc 確保と成否確認 ***********************/
	if (ctlCharMalloc(eMAKE, &text_upper, STR_LEN)) {
  if (ctlCharMalloc(eMAKE, &text_lower, STR_LEN)) {

  /* 文字列生成 */
  display_mode = generText( &text_upper, &text_lower, input_ptr, est_ptr, trans_ptr, lang_mode);

  /* LCD 初期設定 */
  static bool setup = false;
  if(setup == false) { /* 初めの１回限り */
    lcd.begin(16, 2);
    setup = true;
  }

  /* LCD 表示 */
  lcd.clear();
  switch (display_mode){   /* eOOO_XXX (上段文字_下段文字) */
    case eENG_ENG:  
    {
      lcd.setCursor(0, 0);
      lcd.print(text_upper); 
      lcd.setCursor(0, 1);
      lcd.print(text_lower); 
      break;
    }
    case eENG_JAP:  
    {
      lcd.setCursor(0, 0);
      lcd.print(text_upper); 
      lcd.setCursor(0, 1);
      lcd.kana(text_lower); 
      break;
    }
    case eJAP_ENG:
    {
      lcd.setCursor(0, 0);
      lcd.kana(text_upper); 
      lcd.setCursor(0, 1);
      lcd.print(text_lower); 
      break;
    }
    case eJAP_JAP:
    {
      lcd.setCursor(0, 0);
      lcd.kana(text_upper); 
      lcd.setCursor(0, 1);
      lcd.kana(text_lower); 
      break;
    }
  } 

 #if 0//defined(DEBUG)
  Serial.println("-----");
  Serial.print(*text_upper);
  Serial.print(":");
  Serial.println(*(text_upper+1));
  Serial.print(*text_upper, HEX);
  Serial.print(":");
  Serial.println(*(text_upper+1), HEX);
  Serial.println("******");
 #endif
  wait(20);

  /* malloc free */
  ctlCharMalloc(eFREE, &text_upper, STR_LEN);
  ctlCharMalloc(eFREE, &text_lower, STR_LEN);

  /***** malloc 確保失敗 *****************************/
  /* 異常通知 */
  } else { PRINT_ERROR(text_upper); }
  } else { PRINT_ERROR(text_lower); }
}

/***** 非公開関数 ***********************************************/
/****************************************************
 * 関数名　：generText
 * 機能　　：LCD に表示するための文字列を生成
 * 引数　　：[char**] text_upper, [char**] text_lower, 
 *     　　：[char**] input_ptr,  [char**] est_ptr, [char**] trans_ptr, [LangMode_t] lang_mode)
 * 戻り値　：[DisplayMode_t] display_mode
 * 備考　　：
 ***************************************************/
 DisplayMode_t generText( char** text_upper, char** text_lower,  \
                 char** input_ptr, char** est_ptr, char** trans_ptr, LangMode_t lang_mode)
{
  DisplayMode_t display_mode = eENG_ENG;
  int lcd_str_len = 55;
  char msg_lang_mode[lcd_str_len];

  /* 未入力時 */
  if (**input_ptr == '\0') {
    switch (lang_mode){ 
      /* 日本語入力モード */
      case eJAP:  
      {
        char lang_jap[] = "JAP to ENG";
        strcpy_sf( msg_lang_mode, lang_jap, lcd_str_len, 0);
        break;
      }
      /* 英語入力モード */
      case eENG:  
      {
        char lang_eng[] = "ENG to JAP";
        strcpy_sf( msg_lang_mode, lang_eng, lcd_str_len, 0);
        break;
      }
    }
    /* text に反映 */
    strcpy_sf( *text_upper, msg_lang_mode, STR_LEN, 0);
  }
  /* 入力モード中 */
  else if (**trans_ptr == '\0') {
    strcpy_sf( *text_upper, *input_ptr, lcd_str_len, 0);
    strcpy_sf( *text_lower, *est_ptr, lcd_str_len, 0);
    if      (lang_mode == eENG) { display_mode = eENG_ENG; }
    else if (lang_mode == eJAP) { display_mode = eJAP_JAP; }
  }
  /* 入力確定,翻訳モード中 */
  else if (**trans_ptr != '\0') {
    strcpy_sf( *text_upper, *input_ptr, lcd_str_len, 0);
    strcpy_sf( *text_lower, *trans_ptr, lcd_str_len, 0);
    if      (lang_mode == eENG) { display_mode = eENG_JAP; }
    else if (lang_mode == eJAP) { display_mode = eJAP_ENG; }
  }
  return(display_mode);
}