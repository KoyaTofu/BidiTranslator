
#pragma once
/****************************************************
 * ファイル名　：Common.h　
 * 役割　　　　：グローバル共有
 * 作成日　　　：2024.02.04
 ***************************************************/
/* ヘッダファイルまとめてインクルード */ 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdbool.h>

/* スイッチ状態用(AnalKeyMatrix.h) */
 #define OFF 0
 #define ON  1

/*** LCD 設定 ***/
 #include <I2CLiquidCrystal.h>
 #include <Wire.h>
 I2CLiquidCrystal lcd(63,(bool)true);

/*** 文字列の長さ ***/
 #define STR_LEN 55

/*** デバック設定 ***/
 #define DEBUG ON
 #define PRINT_ERROR(n) Serial.println(#n)
 #define PRINT_DEBUG(n) Serial.println(n)

/***** マトリクス用pin 情報 *****/
 /* キーマトリクス-OUTPUT用pin */
 #define NUM_MTRX_OUT_PIN 5
 const int key_output_pin[ NUM_MTRX_OUT_PIN ] = {6,5,4,3,2};

 /* キーマトリクス-INPUT用pin */
 #define NUM_MTRX_IN_PIN 6
 const int key_input_pin[ NUM_MTRX_IN_PIN ] = {13,12,11,10,9,8};

/********** キーコード ******************************/
 typedef enum { KC_NULL,
     /*pin*/ /*13*/ /*12*/ /*11*/   /*10*/ /*09*/ /*08*/
       /*6*/  KC_a,  KC_b,  KC_c,    KC_d,  KC_e,  KC_f,    
       /*5*/  KC_g,  KC_h,  KC_i,    KC_j,  KC_k,  KC_l, 
       /*4*/  KC_m,  KC_n,  KC_o,    KC_p,  KC_q,  KC_r, 
       /*3*/  KC_s,  KC_t,  KC_u,    KC_v,  KC_w,  KC_x, 
       /*2*/  KC_y,  KC_z,  KC_Ctrl, KC_La, KC_Bs, KC_En,
 /*複合キー*/ KC_Spc, KC_Point, KC_Clear
 } KeyCode_t;

/***** 状態管理用 型定義 **************************************/
/***************************************************/
 typedef enum { eENG, eJAP }                    LangMode_t;
 typedef enum { eINPUT, eENTER, eBACK, eCLEAR } OpeMode_t;
 typedef enum { eENG_ENG, eENG_JAP, eJAP_ENG, eJAP_JAP} DisplayMode_t;

 /*** 制御状態 ***/
 typedef struct {
  LangMode_t  lang_mode;
  OpeMode_t   ope_mode;
 } CtlState_t;

 /*** 文字列操作用 ***/
 typedef struct {
  CtlState_t ctl_state;
  char       ascii;
  char*      input_ptr;
  KeyCode_t  key_code;
  uint8_t current_matrix[NUM_MTRX_OUT_PIN] = { 0 };
 } InputState_t;
