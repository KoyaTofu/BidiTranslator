/****************************************************
 * ファイル名　：TransMap.ino
 * 役割　　　　：日英-翻訳用
 * 作成日　　　：2024.**.**
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
 #include "Common.h"

/*** 自ファイルのヘッダ ***/
 #include "TransMap.h"

/***** trans_map をフラッシュメモリ中に格納させる *****/
const char eng1[] PROGMEM = "afghanistan";  const char jap1[] PROGMEM = "ｱﾌｶﾞﾆｽﾀﾝ";
const char eng2[] PROGMEM = "algeria";  const char jap2[] PROGMEM = "ｱﾙｼﾞｪﾘｱ";
const char eng3[] PROGMEM = "antarctica";  const char jap3[] PROGMEM = "ﾅﾝｷｮｸﾀｲｷｯｸ";
const char eng4[] PROGMEM = "argentina";  const char jap4[] PROGMEM = "ｱﾙｾﾞﾝﾁﾝ";
const char eng5[] PROGMEM = "azerbaijan";  const char jap5[] PROGMEM = "ｱｾﾞﾙﾊﾞｲｼﾞｬﾝ";
const char eng6[] PROGMEM = "bangladesh";  const char jap6[] PROGMEM = "ﾊﾞﾝｸﾞﾗﾃﾞｨｼｭ";
const char eng7[] PROGMEM = "barbados";  const char jap7[] PROGMEM = "ﾊﾞﾙﾊﾞﾄﾞｽ";
const char eng8[] PROGMEM = "bosnia and herzegovina";  const char jap8[] PROGMEM = "ﾎﾞｽﾆｱ･ﾍﾙﾂｪｺﾞﾋﾞﾅ";
const char eng9[] PROGMEM = "brazil";  const char jap9[] PROGMEM = "ﾌﾞﾗｼﾞﾙ";
const char eng10[] PROGMEM = "brunei darussalam";  const char jap10[] PROGMEM = "ﾌﾞﾙﾈｲ";
const char eng11[] PROGMEM = "bulgaria";  const char jap11[] PROGMEM = "ﾌﾞﾙｶﾞﾘｱ";
const char eng12[] PROGMEM = "burkina faso";  const char jap12[] PROGMEM = "ﾌﾞﾙｷﾅﾌｧｿ";
const char eng13[] PROGMEM = "burundi";  const char jap13[] PROGMEM = "ﾌﾞﾙﾝｼﾞ";
const char eng14[] PROGMEM = "cambodia";  const char jap14[] PROGMEM = "ｶﾝﾎﾞｼﾞｱ";
const char eng15[] PROGMEM = "canada";  const char jap15[] PROGMEM = "ｶﾅﾀﾞ";
const char eng16[] PROGMEM = "central african republic";  const char jap16[] PROGMEM = "ﾁｭｳｵｳｱﾌﾘｶ";
const char eng17[] PROGMEM = "chad";  const char jap17[] PROGMEM = "ﾁｬﾄﾞ";
const char eng18[] PROGMEM = "chile";  const char jap18[] PROGMEM = "ﾁﾘ";
const char eng19[] PROGMEM = "china";  const char jap19[] PROGMEM = "ﾁｭｳｺﾞｸ";
const char eng20[] PROGMEM = "colombia";  const char jap20[] PROGMEM = "ｺﾛﾝﾋﾞｱ";
const char eng21[] PROGMEM = "costa rica";  const char jap21[] PROGMEM = "ｺｽﾀﾘｶ";
const char eng22[] PROGMEM = "croatia";  const char jap22[] PROGMEM = "ｸﾛｱﾁｱ";
const char eng23[] PROGMEM = "cyprus";  const char jap23[] PROGMEM = "ｷﾌﾟﾛｽ";
const char eng24[] PROGMEM = "czech republic";  const char jap24[] PROGMEM = "ﾁｪｺ";
const char eng25[] PROGMEM = "djibouti";  const char jap25[] PROGMEM = "ｼﾞﾌﾞﾁ";
const char eng26[] PROGMEM = "dominica";  const char jap26[] PROGMEM = "ﾄﾞﾐﾆｶｺｸ";
const char eng27[] PROGMEM = "dominican republic";  const char jap27[] PROGMEM = "ﾄﾞﾐﾆｶｷｮｳﾜｺｸ";
const char eng28[] PROGMEM = "ecuador";  const char jap28[] PROGMEM = "ｴｸｱﾄﾞﾙ";
const char eng29[] PROGMEM = "egypt";  const char jap29[] PROGMEM = "ｴｼﾞﾌﾟﾄ";
const char eng30[] PROGMEM = "el salvador";  const char jap30[] PROGMEM = "ｴﾙｻﾙﾊﾞﾄﾞﾙ";
const char eng31[] PROGMEM = "equatorial guinea";  const char jap31[] PROGMEM = "ｾｷﾄﾞｳｷﾞﾆｱ";
const char eng32[] PROGMEM = "estonia";  const char jap32[] PROGMEM = "ｴｽﾄﾆｱ";
const char eng33[] PROGMEM = "ethiopia";  const char jap33[] PROGMEM = "ｴﾁｵﾋﾟｱ";
const char eng34[] PROGMEM = "finland";  const char jap34[] PROGMEM = "ﾌｨﾝﾗﾝﾄﾞ";
const char eng35[] PROGMEM = "france";  const char jap35[] PROGMEM = "ﾌﾗﾝｽ";
const char eng36[] PROGMEM = "germany";  const char jap36[] PROGMEM = "ﾄﾞｲﾂ";
const char eng37[] PROGMEM = "gibraltar";  const char jap37[] PROGMEM = "ｼﾞﾌﾞﾗﾙﾀﾙ";
const char eng38[] PROGMEM = "greece";  const char jap38[] PROGMEM = "ｷﾞﾘｼｬ";
const char eng39[] PROGMEM = "guatemala";  const char jap39[] PROGMEM = "ｸﾞｱﾃﾏﾗ";
const char eng40[] PROGMEM = "guinea";  const char jap40[] PROGMEM = "ｷﾞﾆｱ";
const char eng41[] PROGMEM = "guinea-bissau";  const char jap41[] PROGMEM = "ｷﾞﾆｱﾋﾞｻｳ";
const char eng42[] PROGMEM = "honduras";  const char jap42[] PROGMEM = "ﾎﾝｼﾞｭﾗｽ";
const char eng43[] PROGMEM = "hong kong";  const char jap43[] PROGMEM = "ﾎﾝｺﾝ";
const char eng44[] PROGMEM = "iceland";  const char jap44[] PROGMEM = "ｱｲｽﾗﾝﾄﾞ";
const char eng45[] PROGMEM = "india";  const char jap45[] PROGMEM = "ｲﾝﾄﾞ";
const char eng46[] PROGMEM = "indonesia";  const char jap46[] PROGMEM = "ｲﾝﾄﾞﾈｼｱ";
const char eng47[] PROGMEM = "iran";  const char jap47[] PROGMEM = "ｲﾗﾝ";
const char eng48[] PROGMEM = "iraq";  const char jap48[] PROGMEM = "ｲﾗｸ";
const char eng49[] PROGMEM = "ireland";  const char jap49[] PROGMEM = "ｱｲﾙﾗﾝﾄﾞ";
const char eng50[] PROGMEM = "israel";  const char jap50[] PROGMEM = "ｲｽﾗｴﾙ";
const char eng51[] PROGMEM = "italy";  const char jap51[] PROGMEM = "ｲﾀﾘｱ";
const char eng52[] PROGMEM = "jamaica";  const char jap52[] PROGMEM = "ｼﾞｬﾏｲｶ";
const char eng53[] PROGMEM = "japan";  const char jap53[] PROGMEM = "ﾆﾎﾝ";
const char eng54[] PROGMEM = "jordan";  const char jap54[] PROGMEM = "ﾖﾙﾀﾞﾝ";
const char eng55[] PROGMEM = "kazakhstan";  const char jap55[] PROGMEM = "ｶｻﾞﾌｽﾀﾝ";
const char eng56[] PROGMEM = "kenya";  const char jap56[] PROGMEM = "ｹﾆｱ";
const char eng57[] PROGMEM = "kiribati";  const char jap57[] PROGMEM = "ｷﾘﾊﾞｽ";
const char eng58[] PROGMEM = "korea";  const char jap58[] PROGMEM = "ｶﾝｺｸ";
const char eng59[] PROGMEM = "kyrgyzstan";  const char jap59[] PROGMEM = "ｷﾙｷﾞｽ";
const char eng60[] PROGMEM = "lebanon";  const char jap60[] PROGMEM = "ﾚﾊﾞﾉﾝ";
const char eng61[] PROGMEM = "lesotho";  const char jap61[] PROGMEM = "ﾚｿﾄ";
const char eng62[] PROGMEM = "liberia";  const char jap62[] PROGMEM = "ﾘﾍﾞﾘｱ";
const char eng63[] PROGMEM = "libyan arab jamahiriya";  const char jap63[] PROGMEM = "ﾘﾋﾞｱ";
const char eng64[] PROGMEM = "liechtenstein";  const char jap64[] PROGMEM = "ﾘﾋﾃﾝｼｭﾀｲﾝ";
const char eng65[] PROGMEM = "luxembourg";  const char jap65[] PROGMEM = "ﾙｸｾﾝﾌﾞﾙｸ";
const char eng66[] PROGMEM = "macao";  const char jap66[] PROGMEM = "ﾏｶｵ";
const char eng67[] PROGMEM = "madagascar";  const char jap67[] PROGMEM = "ﾏﾀﾞｶﾞｽｶﾙ";
const char eng68[] PROGMEM = "maldives";  const char jap68[] PROGMEM = "ﾓﾙﾃﾞｨﾌﾞ";
const char eng69[] PROGMEM = "mexico";  const char jap69[] PROGMEM = "ﾒｷｼｺ";
const char eng70[] PROGMEM = "moldova";  const char jap70[] PROGMEM = "ﾓﾙﾄﾞﾊﾞ";
const char eng71[] PROGMEM = "monaco";  const char jap71[] PROGMEM = "ﾓﾅｺ";
const char eng72[] PROGMEM = "mongolia";  const char jap72[] PROGMEM = "ﾓﾝｺﾞﾙ";
const char eng73[] PROGMEM = "montenegro";  const char jap73[] PROGMEM = "ﾓﾝﾃﾈｸﾞﾛ";
const char eng74[] PROGMEM = "montserrat";  const char jap74[] PROGMEM = "ﾓﾝｾﾗｯﾄ";
const char eng75[] PROGMEM = "morocco";  const char jap75[] PROGMEM = "ﾓﾛｯｺ";
const char eng76[] PROGMEM = "netherlands";  const char jap76[] PROGMEM = "ｵﾗﾝﾀﾞ";
const char eng77[] PROGMEM = "nigeria";  const char jap77[] PROGMEM = "ﾅｲｼﾞｪﾘｱ";
const char eng78[] PROGMEM = "north macedonia";  const char jap78[] PROGMEM = "ｷﾀﾏｹﾄﾞﾆｱ";
const char eng79[] PROGMEM = "pakistan";  const char jap79[] PROGMEM = "ﾊﾟｷｽﾀﾝ";
const char eng80[] PROGMEM = "palestinian territory";  const char jap80[] PROGMEM = "ﾊﾟﾚｽﾁﾅ";
const char eng81[] PROGMEM = "paraguay";  const char jap81[] PROGMEM = "ﾊﾟﾗｸﾞｱｲ";
const char eng82[] PROGMEM = "philippines";  const char jap82[] PROGMEM = "ﾌｨﾘﾋﾟﾝ";
const char eng83[] PROGMEM = "portugal";  const char jap83[] PROGMEM = "ﾎﾟﾙﾄｶﾞﾙ";
const char eng84[] PROGMEM = "puerto rico";  const char jap84[] PROGMEM = "ﾌﾟｴﾙﾄﾘｺ";
const char eng85[] PROGMEM = "reunion";  const char jap85[] PROGMEM = "ﾚﾕﾆｵﾝ";
const char eng86[] PROGMEM = "russian federation";  const char jap86[] PROGMEM = "ﾛｼｱ";
const char eng87[] PROGMEM = "rwanda";  const char jap87[] PROGMEM = "ﾙﾜﾝﾀﾞ";
const char eng88[] PROGMEM = "san marino";  const char jap88[] PROGMEM = "ｻﾝﾏﾘﾉ";
const char eng89[] PROGMEM = "saudi arabia";  const char jap89[] PROGMEM = "ｻｳｼﾞｱﾗﾋﾞｱ";
const char eng90[] PROGMEM = "senegal";  const char jap90[] PROGMEM = "ｾﾈｶﾞﾙ";
const char eng91[] PROGMEM = "seychelles";  const char jap91[] PROGMEM = "ｾｲｼｪﾙ";
const char eng92[] PROGMEM = "sierra leone";  const char jap92[] PROGMEM = "ｼｴﾗﾚｵﾈ";
const char eng93[] PROGMEM = "slovakia";  const char jap93[] PROGMEM = "ｽﾛﾊﾞｷｱ";
const char eng94[] PROGMEM = "slovenia";  const char jap94[] PROGMEM = "ｽﾛﾍﾞﾆｱ";
const char eng95[] PROGMEM = "somalia";  const char jap95[] PROGMEM = "ｿﾏﾘｱ";
const char eng96[] PROGMEM = "south africa";  const char jap96[] PROGMEM = "ﾐﾅﾐｱﾌﾘｶ";
const char eng97[] PROGMEM = "spain";  const char jap97[] PROGMEM = "ｽﾍﾟｲﾝ";
const char eng98[] PROGMEM = "sri lanka";  const char jap98[] PROGMEM = "ｽﾘﾗﾝｶ";
const char eng99[] PROGMEM = "switzerland";  const char jap99[] PROGMEM = "ｽｲｽ";
const char eng100[] PROGMEM = "syrian arab republic";  const char jap100[] PROGMEM = "ｼﾘｱ";
const char eng101[] PROGMEM = "taiwan";  const char jap101[] PROGMEM = "ﾀｲﾜﾝ";
const char eng102[] PROGMEM = "tajikistan";  const char jap102[] PROGMEM = "ﾀｼｷｽﾀﾝ";
const char eng103[] PROGMEM = "tanzania";  const char jap103[] PROGMEM = "ﾀﾝｻﾞﾆｱ";
const char eng104[] PROGMEM = "thailand";  const char jap104[] PROGMEM = "ﾀｲ";
const char eng105[] PROGMEM = "tonga";  const char jap105[] PROGMEM = "ﾄﾝｶﾞ";
const char eng106[] PROGMEM = "tunisia";  const char jap106[] PROGMEM = "ﾁｭﾆｼﾞｱ";
const char eng107[] PROGMEM = "turkey";  const char jap107[] PROGMEM = "ﾄﾙｺ";
const char eng108[] PROGMEM = "turkmenistan";  const char jap108[] PROGMEM = "ﾄﾙｸﾒﾆｽﾀﾝ";
const char eng109[] PROGMEM = "uganda";  const char jap109[] PROGMEM = "ｳｶﾞﾝﾀﾞ";
const char eng110[] PROGMEM = "ukraine";  const char jap110[] PROGMEM = "ｳｸﾗｲﾅ";
const char eng111[] PROGMEM = "united arab emirates";  const char jap111[] PROGMEM = "ｱﾗﾌﾞｼｭﾁｮｳｺｸﾚﾝﾎﾟｳ";
const char eng112[] PROGMEM = "united kingdom";  const char jap112[] PROGMEM = "ｲｷﾞﾘｽ";
const char eng113[] PROGMEM = "united states of america";  const char jap113[] PROGMEM = "ｱﾒﾘｶ";
const char eng114[] PROGMEM = "uruguay";  const char jap114[] PROGMEM = "ｳﾙｸﾞｱｲ";
const char eng115[] PROGMEM = "uzbekistan";  const char jap115[] PROGMEM = "ｳｽﾞﾍﾞｷｽﾀﾝ";
const char eng116[] PROGMEM = "vatican city state";  const char jap116[] PROGMEM = "ﾊﾞﾁｶﾝｼｺｸ";
const char eng117[] PROGMEM = "viet nam";  const char jap117[] PROGMEM = "ﾍﾞﾄﾅﾑ";
const char eng118[] PROGMEM = "yemen";  const char jap118[] PROGMEM = "ｲｴﾒﾝ";
const char eng119[] PROGMEM = "zambia";  const char jap119[] PROGMEM = "ｻﾝﾋﾞｱ";
const char eng120[] PROGMEM = "zimbabwe";  const char jap120[] PROGMEM = "ｼﾞﾝﾊﾞﾌﾞｴ";

const char* const trans_map[TRANS_NUM][2] PROGMEM = {\
{eng1,jap1},\
{eng2,jap2},\
{eng3,jap3},\
{eng4,jap4},\
{eng5,jap5},\
{eng6,jap6},\
{eng7,jap7},\
{eng8,jap8},\
{eng9,jap9},\
{eng10,jap10},\
{eng11,jap11},\
{eng12,jap12},\
{eng13,jap13},\
{eng14,jap14},\
{eng15,jap15},\
{eng16,jap16},\
{eng17,jap17},\
{eng18,jap18},\
{eng19,jap19},\
{eng20,jap20},\
{eng21,jap21},\
{eng22,jap22},\
{eng23,jap23},\
{eng24,jap24},\
{eng25,jap25},\
{eng26,jap26},\
{eng27,jap27},\
{eng28,jap28},\
{eng29,jap29},\
{eng30,jap30},\
{eng31,jap31},\
{eng32,jap32},\
{eng33,jap33},\
{eng34,jap34},\
{eng35,jap35},\
{eng36,jap36},\
{eng37,jap37},\
{eng38,jap38},\
{eng39,jap39},\
{eng40,jap40},\
{eng41,jap41},\
{eng42,jap42},\
{eng43,jap43},\
{eng44,jap44},\
{eng45,jap45},\
{eng46,jap46},\
{eng47,jap47},\
{eng48,jap48},\
{eng49,jap49},\
{eng50,jap50},\
{eng51,jap51},\
{eng52,jap52},\
{eng53,jap53},\
{eng54,jap54},\
{eng55,jap55},\
{eng56,jap56},\
{eng57,jap57},\
{eng58,jap58},\
{eng59,jap59},\
{eng60,jap60},\
{eng61,jap61},\
{eng62,jap62},\
{eng63,jap63},\
{eng64,jap64},\
{eng65,jap65},\
{eng66,jap66},\
{eng67,jap67},\
{eng68,jap68},\
{eng69,jap69},\
{eng70,jap70},\
{eng71,jap71},\
{eng72,jap72},\
{eng73,jap73},\
{eng74,jap74},\
{eng75,jap75},\
{eng76,jap76},\
{eng77,jap77},\
{eng78,jap78},\
{eng79,jap79},\
{eng80,jap80},\
{eng81,jap81},\
{eng82,jap82},\
{eng83,jap83},\
{eng84,jap84},\
{eng85,jap85},\
{eng86,jap86},\
{eng87,jap87},\
{eng88,jap88},\
{eng89,jap89},\
{eng90,jap90},\
{eng91,jap91},\
{eng92,jap92},\
{eng93,jap93},\
{eng94,jap94},\
{eng95,jap95},\
{eng96,jap96},\
{eng97,jap97},\
{eng98,jap98},\
{eng99,jap99},\
{eng100,jap100},\
{eng101,jap101},\
{eng102,jap102},\
{eng103,jap103},\
{eng104,jap104},\
{eng105,jap105},\
{eng106,jap106},\
{eng107,jap107},\
{eng108,jap108},\
{eng109,jap109},\
{eng110,jap110},\
{eng111,jap111},\
{eng112,jap112},\
{eng113,jap113},\
{eng114,jap114},\
{eng115,jap115},\
{eng116,jap116},\
{eng117,jap117},\
{eng118,jap118},\
{eng119,jap119},\
{eng120,jap120}};
