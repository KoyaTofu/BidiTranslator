# BidiTranslator  
## 【概要】  
日本語と英語での入出力に対応した英和-電子辞書。  
より複雑なスイッチ入力を実装することを目的に、PC同様のアルファベット入力方式を採用。  
ローマ字入力に対応、汎用性の高いシステムを意識して作成。  

## 【使用技術・ツール】  
ローマ字および翻訳用データセット：フラッシュ領域に格納  
文字列（書き換えあり）：mallocで生成したヒープ領域に格納  
文字列（書き換えなし）：配列型・スタック領域に格納  
スイッチ部-回路：キーマトリクス方式  

## 【開発環境・使用部品】  
プログラミング-統合開発環境 : Arduino IDE  
回路設計・シミュレーション : Circuit Simulator Applet (https://www.falstad.com/circuit/)   
マイコン : Arduino UNO R3  
その他 : LCD(I2C)1個、スイッチ30個、整流用ダイオード5個、330Ω抵抗6個、10KΩ抵抗２個、ワイヤー  

## 各写真  
### 完成写真  
![完成写真](https://github.com/KoyaTofu/BidiTranslator/assets/163281871/1612d823-1fd8-402a-b990-5d14d4c9a8a0)

### ファイル構造設計
![ファイル構造設計](https://github.com/KoyaTofu/BidiTranslator/assets/163281871/abf4712d-76c1-4c6e-8b98-22492d7a0432)

### キーマトリクス回路
![キーマトリクス回路](https://github.com/KoyaTofu/BidiTranslator/assets/163281871/ad17e14b-5904-4bb8-9ca4-4c3acffc575e)
