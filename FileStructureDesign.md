<< 共用ファイル >>  
・Common.h  (共用変数や構造体などの定義)  
・RomanMap.h .ino  (ローマ字変換-マップ)  
・TransMap.h .ino  (双方向翻訳-マップ)  
・SharedFunction.h .ino (共用関数)&nbsp; {wait,&nbsp; ctlCharMalloc,&nbsp; cmpMap,&nbsp; cpyMap,&nbsp; strcpy_sf}  

*******************************************************************************************
※ ポインタで上書きして反映：reflect()

<<< BOSS:英和 双方向翻訳機 >>>  BidiTranslator  
┃  
┣━━ < キーマトリクス取得 > GetKeyMatrix&emsp;  {debounce}  
┃&emsp;&emsp; getKeyMatrix( [uint8_t] key_matrix[5],&nbsp; [int] row )    
┃&emsp;&emsp;&emsp;&emsp; return()&emsp; reflect( [uint8_t] key_matrix[5] )  
┃  
┣━━ << 入力管理 >>  ManageInput&emsp;  {analKeyCode,&nbsp; comboEvent}  
┃&emsp;┃&emsp;&emsp; manageInput( [InputState_t] input_state )&emsp; return( [InputState_t] input_state )  
┃&emsp;┃  
┃&emsp;┣━ < キー入力情報分析-取得 > AnalKeyMatrix&emsp;  {calcKeyCode}  
┃&emsp;┃&emsp;&emsp; analKeyMatrix( [uint8_t] current_matrix[5] )&emsp; return( [KeyCode_t] key_code )  
┃&emsp;┃  
┃&emsp;┗━ < 制御状態遷移 >  TransCtlState  
┃&emsp;&emsp;&emsp; transCtlState( [InputState_t] input_state )&emsp; return( [CtlState_t] ctl_state )  
┃  
┣━ << 文字列操作 >> OperateStr  
┃&emsp;┃&emsp;&emsp; operateStr( [InputState_t] input_state,&nbsp; [char**] input_ptr,&nbsp; [char**] trans_ptr,&nbsp; [char**] est_ptr )  
┃&emsp;┃&emsp;&emsp;&emsp;&emsp; return()&emsp; reflect( [char**] input_ptr,&nbsp; [char**] trans_ptr,&nbsp; [char**] est_ptr )  
┃&emsp;┃   
┃&emsp;┣━ < 英和 翻訳 > Translation  
┃&emsp;┃&emsp;&emsp; translation( [char**] trans_ptr,&nbsp; [char**] input_ptr,&nbsp; [LangMode_t] lang_mode)  
┃&emsp;┃&emsp;&emsp;&emsp;&emsp; return()&emsp; reflect( [char**] trans_ptr )  
┃&emsp;┃  
┃&emsp;┣━ < 文字列生成(ローマ字変換) > GenrStr&emsp; {cnvtRoman}    
┃&emsp;┃&emsp;&emsp; genrStr( [char**] input_ptr,&nbsp; [char] ascii,&nbsp; [LangMode_t] lang_mode)  
┃&emsp;┃&emsp;&emsp;&emsp;&emsp; return()&emsp; reflect( [char**] input_ptr )  
┃&emsp;┃  
┃&emsp;┗━ < 入力文字列予測 > EstStr  
┃&emsp;&emsp;&emsp; estStr( [char**] est_ptr,&nbsp; [char**] input_ptr,&nbsp; [LangMode_t] lang_mode )  
┃&emsp;&emsp;&emsp;&emsp;&emsp; return()&emsp; reflect( [char**] est_ptr )  
┃   
┗━ << LCD 表示処理 >> DisplayLcd&emsp;  {generText}  
&emsp;&emsp; displayLcd( [char**] input_ptr,&nbsp; [char**] est_ptr,&nbsp; [char**] trans_ptr,&nbsp; [LangMode_t] lang_mode)  
