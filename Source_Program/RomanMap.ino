/****************************************************
 * ファイル名　：RomanMap.ino
 * 役割　　　　：ローマ字変換用
 * 作成日　　　：2024.03.05
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
 #include "Common.h"
/*** 自ファイルのヘッダ ***/
 #include "RomanMap.h"

/* アルファベットa~z */
char alph[27] = "abcdefghijklmnopqrstuvwxyz";

/* roman_map 中において頭文字が a~z の場所 (Lから始まるローマ字は使われていないから0) */
int alph_site[26] = {0, 1, 12, 17, 46, 47, 56, 71, 89, 90, 98, 0, 117, 132, 147, 148,\
 163, 168, 183, 203, 237, 238, 247, 253, 271, 276};

/***** roman_map をフラッシュメモリ中に格納させる *****/
const char a0[] PROGMEM = "a";  const char a1[] PROGMEM = "ｱ";
const char ba0[] PROGMEM = "ba";  const char ba1[] PROGMEM = "ﾊﾞ";
const char bb0[] PROGMEM = "bb";  const char bb1[] PROGMEM = "ｯb";
const char be0[] PROGMEM = "be";  const char be1[] PROGMEM = "ﾍﾞ";
const char bi0[] PROGMEM = "bi";  const char bi1[] PROGMEM = "ﾋﾞ";
const char bo0[] PROGMEM = "bo";  const char bo1[] PROGMEM = "ﾎﾞ";
const char bu0[] PROGMEM = "bu";  const char bu1[] PROGMEM = "ﾌﾞ";
const char bya0[] PROGMEM = "bya";  const char bya1[] PROGMEM = "ﾋﾞｬ";
const char bye0[] PROGMEM = "bye";  const char bye1[] PROGMEM = "ﾋﾞｪ";
const char byi0[] PROGMEM = "byi";  const char byi1[] PROGMEM = "ﾋﾞｨ";
const char byo0[] PROGMEM = "byo";  const char byo1[] PROGMEM = "ﾋﾞｮ";
const char byu0[] PROGMEM = "byu";  const char byu1[] PROGMEM = "ﾋﾞｭ";
const char cha0[] PROGMEM = "cha";  const char cha1[] PROGMEM = "ﾁｬ";
const char che0[] PROGMEM = "che";  const char che1[] PROGMEM = "ﾁｪ";
const char chi0[] PROGMEM = "chi";  const char chi1[] PROGMEM = "ﾁﾁ";
const char cho0[] PROGMEM = "cho";  const char cho1[] PROGMEM = "ﾁｮ";
const char chu0[] PROGMEM = "chu";  const char chu1[] PROGMEM = "ﾁｭ";
const char da0[] PROGMEM = "da";  const char da1[] PROGMEM = "ﾀﾞ";
const char dd0[] PROGMEM = "dd";  const char dd1[] PROGMEM = "ｯd";
const char de0[] PROGMEM = "de";  const char de1[] PROGMEM = "ﾃﾞ";
const char dha0[] PROGMEM = "dha";  const char dha1[] PROGMEM = "ﾃﾞｬ";
const char dhe0[] PROGMEM = "dhe";  const char dhe1[] PROGMEM = "ﾃﾞｪ";
const char dhi0[] PROGMEM = "dhi";  const char dhi1[] PROGMEM = "ﾃﾞｨ";
const char dho0[] PROGMEM = "dho";  const char dho1[] PROGMEM = "ﾃﾞｮ";
const char dhu0[] PROGMEM = "dhu";  const char dhu1[] PROGMEM = "ﾃﾞｭ";
const char di0[] PROGMEM = "di";  const char di1[] PROGMEM = "ﾁﾞ";
const char dja0[] PROGMEM = "dja";  const char dja1[] PROGMEM = "ﾃﾞｬ";
const char dji0[] PROGMEM = "dji";  const char dji1[] PROGMEM = "ﾃﾞｨ";
const char djo0[] PROGMEM = "djo";  const char djo1[] PROGMEM = "ﾃﾞｮ";
const char dju0[] PROGMEM = "dju";  const char dju1[] PROGMEM = "ﾃﾞｭ";
const char do0[] PROGMEM = "do";  const char do1[] PROGMEM = "ﾄﾞ";
const char du0[] PROGMEM = "du";  const char du1[] PROGMEM = "ﾂﾞ";
const char dva0[] PROGMEM = "dva";  const char dva1[] PROGMEM = "ﾄﾞｧ";
const char dve0[] PROGMEM = "dve";  const char dve1[] PROGMEM = "ﾄﾞｪ";
const char dvi0[] PROGMEM = "dvi";  const char dvi1[] PROGMEM = "ﾄﾞｨ";
const char dvu0[] PROGMEM = "dvu";  const char dvu1[] PROGMEM = "ﾄﾞｩ";
const char dwa0[] PROGMEM = "dwa";  const char dwa1[] PROGMEM = "ﾄﾞｧ";
const char dwe0[] PROGMEM = "dwe";  const char dwe1[] PROGMEM = "ﾄﾞｪ";
const char dwi0[] PROGMEM = "dwi";  const char dwi1[] PROGMEM = "ﾄﾞｨ";
const char dwo0[] PROGMEM = "dwo";  const char dwo1[] PROGMEM = "ﾄﾞｫ";
const char dwu0[] PROGMEM = "dwu";  const char dwu1[] PROGMEM = "ﾄﾞｩ";
const char dya0[] PROGMEM = "dya";  const char dya1[] PROGMEM = "ﾁﾞｬ";
const char dye0[] PROGMEM = "dye";  const char dye1[] PROGMEM = "ﾁﾞｪ";
const char dyi0[] PROGMEM = "dyi";  const char dyi1[] PROGMEM = "ﾁﾞｨ";
const char dyo0[] PROGMEM = "dyo";  const char dyo1[] PROGMEM = "ﾁﾞｮ";
const char dyu0[] PROGMEM = "dyu";  const char dyu1[] PROGMEM = "ﾁﾞｭ";
const char e0[] PROGMEM = "e";  const char e1[] PROGMEM = "ｴ";
const char fa0[] PROGMEM = "fa";  const char fa1[] PROGMEM = "ﾌｧ";
const char fe0[] PROGMEM = "fe";  const char fe1[] PROGMEM = "ﾌｪ";
const char ff0[] PROGMEM = "ff";  const char ff1[] PROGMEM = "ｯf";
const char fi0[] PROGMEM = "fi";  const char fi1[] PROGMEM = "ﾌｨ";
const char fo0[] PROGMEM = "fo";  const char fo1[] PROGMEM = "ﾌｫ";
const char fu0[] PROGMEM = "fu";  const char fu1[] PROGMEM = "ﾌ";
const char fya0[] PROGMEM = "fya";  const char fya1[] PROGMEM = "ﾌｬ";
const char fyo0[] PROGMEM = "fyo";  const char fyo1[] PROGMEM = "ﾌｮ";
const char fyu0[] PROGMEM = "fyu";  const char fyu1[] PROGMEM = "ﾌｭ";
const char ga0[] PROGMEM = "ga";  const char ga1[] PROGMEM = "ｶﾞ";
const char ge0[] PROGMEM = "ge";  const char ge1[] PROGMEM = "ｹﾞ";
const char gg0[] PROGMEM = "gg";  const char gg1[] PROGMEM = "ｯg";
const char gi0[] PROGMEM = "gi";  const char gi1[] PROGMEM = "ｷﾞ";
const char go0[] PROGMEM = "go";  const char go1[] PROGMEM = "ｺﾞ";
const char gu0[] PROGMEM = "gu";  const char gu1[] PROGMEM = "ｸﾞ";
const char gwa0[] PROGMEM = "gwa";  const char gwa1[] PROGMEM = "ｸﾞｧ";
const char gwe0[] PROGMEM = "gwe";  const char gwe1[] PROGMEM = "ｸﾞｪ";
const char gwi0[] PROGMEM = "gwi";  const char gwi1[] PROGMEM = "ｸﾞｨ";
const char gwo0[] PROGMEM = "gwo";  const char gwo1[] PROGMEM = "ｸﾞｫ";
const char gya0[] PROGMEM = "gya";  const char gya1[] PROGMEM = "ｷﾞｬ";
const char gye0[] PROGMEM = "gye";  const char gye1[] PROGMEM = "ｷﾞｪ";
const char gyi0[] PROGMEM = "gyi";  const char gyi1[] PROGMEM = "ｷﾞｨ";
const char gyo0[] PROGMEM = "gyo";  const char gyo1[] PROGMEM = "ｷﾞｮ";
const char gyu0[] PROGMEM = "gyu";  const char gyu1[] PROGMEM = "ｷﾞｭ";
const char ha0[] PROGMEM = "ha";  const char ha1[] PROGMEM = "ﾊ";
const char he0[] PROGMEM = "he";  const char he1[] PROGMEM = "ﾍ";
const char hh0[] PROGMEM = "hh";  const char hh1[] PROGMEM = "ｯh";
const char hi0[] PROGMEM = "hi";  const char hi1[] PROGMEM = "ﾋ";
const char ho0[] PROGMEM = "ho";  const char ho1[] PROGMEM = "ﾎ";
const char hu0[] PROGMEM = "hu";  const char hu1[] PROGMEM = "ﾌ";
const char hwa0[] PROGMEM = "hwa";  const char hwa1[] PROGMEM = "ﾌｧ";
const char hwe0[] PROGMEM = "hwe";  const char hwe1[] PROGMEM = "ﾌｪ";
const char hwi0[] PROGMEM = "hwi";  const char hwi1[] PROGMEM = "ﾌｨ";
const char hwo0[] PROGMEM = "hwo";  const char hwo1[] PROGMEM = "ﾌｫ";
const char hwya0[] PROGMEM = "hwya";  const char hwya1[] PROGMEM = "ﾌｬ";
const char hwyo0[] PROGMEM = "hwyo";  const char hwyo1[] PROGMEM = "ﾌｮ";
const char hwyu0[] PROGMEM = "hwyu";  const char hwyu1[] PROGMEM = "ﾌｭ";
const char hya0[] PROGMEM = "hya";  const char hya1[] PROGMEM = "ﾋｬ";
const char hye0[] PROGMEM = "hye";  const char hye1[] PROGMEM = "ﾋｪ";
const char hyi0[] PROGMEM = "hyi";  const char hyi1[] PROGMEM = "ﾋｨ";
const char hyo0[] PROGMEM = "hyo";  const char hyo1[] PROGMEM = "ﾋｮ";
const char hyu0[] PROGMEM = "hyu";  const char hyu1[] PROGMEM = "ﾋｭ";
const char i0[] PROGMEM = "i";  const char i1[] PROGMEM = "ｲ";
const char ja0[] PROGMEM = "ja";  const char ja1[] PROGMEM = "ｼﾞｬ";
const char ji0[] PROGMEM = "ji";  const char ji1[] PROGMEM = "ｼﾞ";
const char jj0[] PROGMEM = "jj";  const char jj1[] PROGMEM = "ｯj";
const char jo0[] PROGMEM = "jo";  const char jo1[] PROGMEM = "ｼﾞｮ";
const char ju0[] PROGMEM = "ju";  const char ju1[] PROGMEM = "ｼﾞｭ";
const char jya0[] PROGMEM = "jya";  const char jya1[] PROGMEM = "ｼﾞｬ";
const char jyu0[] PROGMEM = "jyu";  const char jyu1[] PROGMEM = "ｼﾞｭ";
const char jyo0[] PROGMEM = "jyo";  const char jyo1[] PROGMEM = "ｼﾞｮ";
const char ka0[] PROGMEM = "ka";  const char ka1[] PROGMEM = "ｶ";
const char ke0[] PROGMEM = "ke";  const char ke1[] PROGMEM = "ｹ";
const char ki0[] PROGMEM = "ki";  const char ki1[] PROGMEM = "ｷ";
const char kk0[] PROGMEM = "kk";  const char kk1[] PROGMEM = "ｯk";
const char ko0[] PROGMEM = "ko";  const char ko1[] PROGMEM = "ｺ";
const char ku0[] PROGMEM = "ku";  const char ku1[] PROGMEM = "ｸ";
const char kua0[] PROGMEM = "kua";  const char kua1[] PROGMEM = "ｸｧ";
const char kue0[] PROGMEM = "kue";  const char kue1[] PROGMEM = "ｸｪ";
const char kui0[] PROGMEM = "kui";  const char kui1[] PROGMEM = "ｸｨ";
const char kuo0[] PROGMEM = "kuo";  const char kuo1[] PROGMEM = "ｸｫ";
const char kwa0[] PROGMEM = "kwa";  const char kwa1[] PROGMEM = "ｸｧ";
const char kwe0[] PROGMEM = "kwe";  const char kwe1[] PROGMEM = "ｸｪ";
const char kwi0[] PROGMEM = "kwi";  const char kwi1[] PROGMEM = "ｸｨ";
const char kwo0[] PROGMEM = "kwo";  const char kwo1[] PROGMEM = "ｸｫ";
const char kya0[] PROGMEM = "kya";  const char kya1[] PROGMEM = "ｷｬ";
const char kye0[] PROGMEM = "kye";  const char kye1[] PROGMEM = "ｷｪ";
const char kyi0[] PROGMEM = "kyi";  const char kyi1[] PROGMEM = "ｷｨ";
const char kyo0[] PROGMEM = "kyo";  const char kyo1[] PROGMEM = "ｷｮ";
const char kyu0[] PROGMEM = "kyu";  const char kyu1[] PROGMEM = "ｷｭ";
const char ma0[] PROGMEM = "ma";  const char ma1[] PROGMEM = "ﾏ";
const char me0[] PROGMEM = "me";  const char me1[] PROGMEM = "ﾒ";
const char mi0[] PROGMEM = "mi";  const char mi1[] PROGMEM = "ﾐ";
const char mm0[] PROGMEM = "mm";  const char mm1[] PROGMEM = "ｯm";
const char mo0[] PROGMEM = "mo";  const char mo1[] PROGMEM = "ﾓ";
const char mu0[] PROGMEM = "mu";  const char mu1[] PROGMEM = "ﾑ";
const char mwa0[] PROGMEM = "mwa";  const char mwa1[] PROGMEM = "ﾑｧ";
const char mwe0[] PROGMEM = "mwe";  const char mwe1[] PROGMEM = "ﾑｪ";
const char mwi0[] PROGMEM = "mwi";  const char mwi1[] PROGMEM = "ﾑｨ";
const char mwo0[] PROGMEM = "mwo";  const char mwo1[] PROGMEM = "ﾑｫ";
const char mya0[] PROGMEM = "mya";  const char mya1[] PROGMEM = "ﾐｬ";
const char mye0[] PROGMEM = "mye";  const char mye1[] PROGMEM = "ﾐｪ";
const char myi0[] PROGMEM = "myi";  const char myi1[] PROGMEM = "ﾐｨ";
const char myo0[] PROGMEM = "myo";  const char myo1[] PROGMEM = "ﾐｮ";
const char myu0[] PROGMEM = "myu";  const char myu1[] PROGMEM = "ﾐｭ";
const char nn0[] PROGMEM = "nn";  const char nn1[] PROGMEM = "ﾝ";
const char na0[] PROGMEM = "na";  const char na1[] PROGMEM = "ﾅ";
const char ne0[] PROGMEM = "ne";  const char ne1[] PROGMEM = "ﾈ";
const char ni0[] PROGMEM = "ni";  const char ni1[] PROGMEM = "ﾆ";
const char no0[] PROGMEM = "no";  const char no1[] PROGMEM = "ﾉ";
const char nu0[] PROGMEM = "nu";  const char nu1[] PROGMEM = "ﾇ";
const char nwa0[] PROGMEM = "nwa";  const char nwa1[] PROGMEM = "ﾇｧ";
const char nwe0[] PROGMEM = "nwe";  const char nwe1[] PROGMEM = "ﾇｪ";
const char nwi0[] PROGMEM = "nwi";  const char nwi1[] PROGMEM = "ﾇｨ";
const char nwo0[] PROGMEM = "nwo";  const char nwo1[] PROGMEM = "ﾇｫ";
const char nya0[] PROGMEM = "nya";  const char nya1[] PROGMEM = "ﾆｬ";
const char nye0[] PROGMEM = "nye";  const char nye1[] PROGMEM = "ﾆｪ";
const char nyi0[] PROGMEM = "nyi";  const char nyi1[] PROGMEM = "ﾆｨ";
const char nyo0[] PROGMEM = "nyo";  const char nyo1[] PROGMEM = "ﾆｮ";
const char nyu0[] PROGMEM = "nyu";  const char nyu1[] PROGMEM = "ﾆｭ";
const char o0[] PROGMEM = "o";  const char o1[] PROGMEM = "ｵ";
const char pa0[] PROGMEM = "pa";  const char pa1[] PROGMEM = "ﾊﾟ";
const char pe0[] PROGMEM = "pe";  const char pe1[] PROGMEM = "ﾍﾟ";
const char pi0[] PROGMEM = "pi";  const char pi1[] PROGMEM = "ﾋﾟ";
const char po0[] PROGMEM = "po";  const char po1[] PROGMEM = "ﾎﾟ";
const char pp0[] PROGMEM = "pp";  const char pp1[] PROGMEM = "ｯp";
const char pu0[] PROGMEM = "pu";  const char pu1[] PROGMEM = "ﾌﾟ";
const char pwa0[] PROGMEM = "pwa";  const char pwa1[] PROGMEM = "ﾌﾟｧ";
const char pwe0[] PROGMEM = "pwe";  const char pwe1[] PROGMEM = "ﾌﾟｪ";
const char pwi0[] PROGMEM = "pwi";  const char pwi1[] PROGMEM = "ﾌﾟｨ";
const char pwo0[] PROGMEM = "pwo";  const char pwo1[] PROGMEM = "ﾌﾟｫ";
const char pya0[] PROGMEM = "pya";  const char pya1[] PROGMEM = "ﾋﾟｬ";
const char pye0[] PROGMEM = "pye";  const char pye1[] PROGMEM = "ﾋﾟｪ";
const char pyi0[] PROGMEM = "pyi";  const char pyi1[] PROGMEM = "ﾋﾟｨ";
const char pyo0[] PROGMEM = "pyo";  const char pyo1[] PROGMEM = "ﾋﾟｮ";
const char pyu0[] PROGMEM = "pyu";  const char pyu1[] PROGMEM = "ﾋﾟｭ";
const char qa0[] PROGMEM = "qa";  const char qa1[] PROGMEM = "ｸｧ";
const char qe0[] PROGMEM = "qe";  const char qe1[] PROGMEM = "ｸｪ";
const char qi0[] PROGMEM = "qi";  const char qi1[] PROGMEM = "ｸｨ";
const char qo0[] PROGMEM = "qo";  const char qo1[] PROGMEM = "ｸｫ";
const char qu0[] PROGMEM = "qu";  const char qu1[] PROGMEM = "ｸ";
const char ra0[] PROGMEM = "ra";  const char ra1[] PROGMEM = "ﾗ";
const char re0[] PROGMEM = "re";  const char re1[] PROGMEM = "ﾚ";
const char ri0[] PROGMEM = "ri";  const char ri1[] PROGMEM = "ﾘ";
const char ro0[] PROGMEM = "ro";  const char ro1[] PROGMEM = "ﾛ";
const char rr0[] PROGMEM = "rr";  const char rr1[] PROGMEM = "ｯr";
const char ru0[] PROGMEM = "ru";  const char ru1[] PROGMEM = "ﾙ";
const char rwa0[] PROGMEM = "rwa";  const char rwa1[] PROGMEM = "ﾙｧ";
const char rwe0[] PROGMEM = "rwe";  const char rwe1[] PROGMEM = "ﾙｪ";
const char rwi0[] PROGMEM = "rwi";  const char rwi1[] PROGMEM = "ﾙｨ";
const char rwo0[] PROGMEM = "rwo";  const char rwo1[] PROGMEM = "ﾙｫ";
const char rya0[] PROGMEM = "rya";  const char rya1[] PROGMEM = "ﾘｬ";
const char rye0[] PROGMEM = "rye";  const char rye1[] PROGMEM = "ﾘｪ";
const char ryi0[] PROGMEM = "ryi";  const char ryi1[] PROGMEM = "ﾘｨ";
const char ryo0[] PROGMEM = "ryo";  const char ryo1[] PROGMEM = "ﾘｮ";
const char ryu0[] PROGMEM = "ryu";  const char ryu1[] PROGMEM = "ﾘｭ";
const char sa0[] PROGMEM = "sa";  const char sa1[] PROGMEM = "ｻ";
const char se0[] PROGMEM = "se";  const char se1[] PROGMEM = "ｾ";
const char sha0[] PROGMEM = "sha";  const char sha1[] PROGMEM = "ｼｬ";
const char shi0[] PROGMEM = "shi";  const char shi1[] PROGMEM = "ｼ";
const char sho0[] PROGMEM = "sho";  const char sho1[] PROGMEM = "ｼｮ";
const char shu0[] PROGMEM = "shu";  const char shu1[] PROGMEM = "ｼｭ";
const char si0[] PROGMEM = "si";  const char si1[] PROGMEM = "ｼ";
const char so0[] PROGMEM = "so";  const char so1[] PROGMEM = "ｿ";
const char ss0[] PROGMEM = "ss";  const char ss1[] PROGMEM = "ｯs";
const char su0[] PROGMEM = "su";  const char su1[] PROGMEM = "ｽ";
const char swa0[] PROGMEM = "swa";  const char swa1[] PROGMEM = "ｽｧ";
const char swe0[] PROGMEM = "swe";  const char swe1[] PROGMEM = "ｽｪ";
const char swi0[] PROGMEM = "swi";  const char swi1[] PROGMEM = "ｽｨ";
const char swo0[] PROGMEM = "swo";  const char swo1[] PROGMEM = "ｽｫ";
const char swu0[] PROGMEM = "swu";  const char swu1[] PROGMEM = "ｽｩ";
const char sya0[] PROGMEM = "sya";  const char sya1[] PROGMEM = "ｼｬ";
const char sye0[] PROGMEM = "sye";  const char sye1[] PROGMEM = "ｼｪ";
const char syi0[] PROGMEM = "syi";  const char syi1[] PROGMEM = "ｼｨ";
const char syo0[] PROGMEM = "syo";  const char syo1[] PROGMEM = "ｼｮ";
const char syu0[] PROGMEM = "syu";  const char syu1[] PROGMEM = "ｼｭ";
const char ta0[] PROGMEM = "ta";  const char ta1[] PROGMEM = "ﾀ";
const char te0[] PROGMEM = "te";  const char te1[] PROGMEM = "ﾃ";
const char tha0[] PROGMEM = "tha";  const char tha1[] PROGMEM = "ﾃｬ";
const char the0[] PROGMEM = "the";  const char the1[] PROGMEM = "ﾃｪ";
const char thi0[] PROGMEM = "thi";  const char thi1[] PROGMEM = "ﾃｨ";
const char tho0[] PROGMEM = "tho";  const char tho1[] PROGMEM = "ﾃｮ";
const char thu0[] PROGMEM = "thu";  const char thu1[] PROGMEM = "ﾃｭ";
const char ti0[] PROGMEM = "ti";  const char ti1[] PROGMEM = "ﾁ";
const char tja0[] PROGMEM = "tja";  const char tja1[] PROGMEM = "ﾃｬ";
const char tji0[] PROGMEM = "tji";  const char tji1[] PROGMEM = "ﾃｨ";
const char tjo0[] PROGMEM = "tjo";  const char tjo1[] PROGMEM = "ﾃｮ";
const char tju0[] PROGMEM = "tju";  const char tju1[] PROGMEM = "ﾃｭ";
const char to0[] PROGMEM = "to";  const char to1[] PROGMEM = "ﾄ";
const char tsa0[] PROGMEM = "tsa";  const char tsa1[] PROGMEM = "ﾂｧ";
const char tse0[] PROGMEM = "tse";  const char tse1[] PROGMEM = "ﾂｪ";
const char tsi0[] PROGMEM = "tsi";  const char tsi1[] PROGMEM = "ﾂｨ";
const char tso0[] PROGMEM = "tso";  const char tso1[] PROGMEM = "ﾂｫ";
const char tsu0[] PROGMEM = "tsu";  const char tsu1[] PROGMEM = "ﾂﾂ";
const char tt0[] PROGMEM = "tt";  const char tt1[] PROGMEM = "ｯt";
const char tu0[] PROGMEM = "tu";  const char tu1[] PROGMEM = "ﾂ";
const char tva0[] PROGMEM = "tva";  const char tva1[] PROGMEM = "ﾄｧ";
const char tve0[] PROGMEM = "tve";  const char tve1[] PROGMEM = "ﾄｪ";
const char tvi0[] PROGMEM = "tvi";  const char tvi1[] PROGMEM = "ﾄｨ";
const char tvu0[] PROGMEM = "tvu";  const char tvu1[] PROGMEM = "ﾄｩ";
const char twa0[] PROGMEM = "twa";  const char twa1[] PROGMEM = "ﾄｧ";
const char twe0[] PROGMEM = "twe";  const char twe1[] PROGMEM = "ﾄｪ";
const char twi0[] PROGMEM = "twi";  const char twi1[] PROGMEM = "ﾄｨ";
const char two0[] PROGMEM = "two";  const char two1[] PROGMEM = "ﾄｫ";
const char twu0[] PROGMEM = "twu";  const char twu1[] PROGMEM = "ﾄｩ";
const char tya0[] PROGMEM = "tya";  const char tya1[] PROGMEM = "ﾁｬ";
const char tye0[] PROGMEM = "tye";  const char tye1[] PROGMEM = "ﾁｪ";
const char tyi0[] PROGMEM = "tyi";  const char tyi1[] PROGMEM = "ﾁｨ";
const char tyo0[] PROGMEM = "tyo";  const char tyo1[] PROGMEM = "ﾁｮ";
const char tyu0[] PROGMEM = "tyu";  const char tyu1[] PROGMEM = "ﾁｭ";
const char u0[] PROGMEM = "u";  const char u1[] PROGMEM = "ｳ";
const char va0[] PROGMEM = "va";  const char va1[] PROGMEM = "ｳﾞｧ";
const char ve0[] PROGMEM = "ve";  const char ve1[] PROGMEM = "ｳﾞｪ";
const char vi0[] PROGMEM = "vi";  const char vi1[] PROGMEM = "ｳﾞｨ";
const char vo0[] PROGMEM = "vo";  const char vo1[] PROGMEM = "ｳﾞｫ";
const char vu0[] PROGMEM = "vu";  const char vu1[] PROGMEM = "ｳﾞ";
const char vvu0[] PROGMEM = "vvu";  const char vvu1[] PROGMEM = "ｯｳﾞ";
const char vya0[] PROGMEM = "vya";  const char vya1[] PROGMEM = "ｳﾞｬ";
const char vyo0[] PROGMEM = "vyo";  const char vyo1[] PROGMEM = "ｳﾞｮ";
const char vyu0[] PROGMEM = "vyu";  const char vyu1[] PROGMEM = "ｳﾞｭ";
const char wa0[] PROGMEM = "wa";  const char wa1[] PROGMEM = "ﾜ";
const char we0[] PROGMEM = "we";  const char we1[] PROGMEM = "ｳｪ";
const char wha0[] PROGMEM = "wha";  const char wha1[] PROGMEM = "ｳｧ";
const char wi0[] PROGMEM = "wi";  const char wi1[] PROGMEM = "ｳｨ";
const char wo0[] PROGMEM = "wo";  const char wo1[] PROGMEM = "ｦ";
const char ww0[] PROGMEM = "ww";  const char ww1[] PROGMEM = "ｯw";
const char xa0[] PROGMEM = "xa";  const char xa1[] PROGMEM = "ｧ";
const char xe0[] PROGMEM = "xe";  const char xe1[] PROGMEM = "ｪ";
const char xi0[] PROGMEM = "xi";  const char xi1[] PROGMEM = "ｨ";
const char xo0[] PROGMEM = "xo";  const char xo1[] PROGMEM = "ｫ";
const char xtu0[] PROGMEM = "xtu";  const char xtu1[] PROGMEM = "ｯ";
const char xu0[] PROGMEM = "xu";  const char xu1[] PROGMEM = "ｩ";
const char xxa0[] PROGMEM = "xxa";  const char xxa1[] PROGMEM = "ｯｧ";
const char xxe0[] PROGMEM = "xxe";  const char xxe1[] PROGMEM = "ｯｪ";
const char xxi0[] PROGMEM = "xxi";  const char xxi1[] PROGMEM = "ｯｨ";
const char xxo0[] PROGMEM = "xxo";  const char xxo1[] PROGMEM = "ｯｫ";
const char xxu0[] PROGMEM = "xxu";  const char xxu1[] PROGMEM = "ｯｩ";
const char xxwa0[] PROGMEM = "xxwa";  const char xxwa1[] PROGMEM = "ｯﾜ";
const char xxya0[] PROGMEM = "xxya";  const char xxya1[] PROGMEM = "ｯｬ";
const char xxyo0[] PROGMEM = "xxyo";  const char xxyo1[] PROGMEM = "ｯｮ";
const char xxyu0[] PROGMEM = "xxyu";  const char xxyu1[] PROGMEM = "ｯｭ";
const char xya0[] PROGMEM = "xya";  const char xya1[] PROGMEM = "ｬ";
const char xyo0[] PROGMEM = "xyo";  const char xyo1[] PROGMEM = "ｮ";
const char xyu0[] PROGMEM = "xyu";  const char xyu1[] PROGMEM = "ｭ";
const char ya0[] PROGMEM = "ya";  const char ya1[] PROGMEM = "ﾔ";
const char ye0[] PROGMEM = "ye";  const char ye1[] PROGMEM = "ｲｪ";
const char yo0[] PROGMEM = "yo";  const char yo1[] PROGMEM = "ﾖ";
const char yu0[] PROGMEM = "yu";  const char yu1[] PROGMEM = "ﾕ";
const char yy0[] PROGMEM = "yy";  const char yy1[] PROGMEM = "ｯy";
const char za0[] PROGMEM = "za";  const char za1[] PROGMEM = "ｻﾞ";
const char ze0[] PROGMEM = "ze";  const char ze1[] PROGMEM = "ｾﾞ";
const char zi0[] PROGMEM = "zi";  const char zi1[] PROGMEM = "ｼﾞ";
const char zo0[] PROGMEM = "zo";  const char zo1[] PROGMEM = "ｿﾞ";
const char zu0[] PROGMEM = "zu";  const char zu1[] PROGMEM = "ｽﾞ";
const char zwa0[] PROGMEM = "zwa";  const char zwa1[] PROGMEM = "ｽﾞｧ";
const char zwe0[] PROGMEM = "zwe";  const char zwe1[] PROGMEM = "ｽﾞｪ";
const char zwi0[] PROGMEM = "zwi";  const char zwi1[] PROGMEM = "ｽﾞｨ";
const char zwo0[] PROGMEM = "zwo";  const char zwo1[] PROGMEM = "ｽﾞｫ";
const char zwu0[] PROGMEM = "zwu";  const char zwu1[] PROGMEM = "ｽﾞｩ";
const char zya0[] PROGMEM = "zya";  const char zya1[] PROGMEM = "ｼﾞｬ";
const char zye0[] PROGMEM = "zye";  const char zye1[] PROGMEM = "ｼﾞｪ";
const char zyi0[] PROGMEM = "zyi";  const char zyi1[] PROGMEM = "ｼﾞｨ";
const char zyo0[] PROGMEM = "zyo";  const char zyo1[] PROGMEM = "ｼﾞｮ";
const char zyu0[] PROGMEM = "zyu";  const char zyu1[] PROGMEM = "ｼﾞｭ";
const char zz0[] PROGMEM = "zz";  const char zz1[] PROGMEM = "ｯz";

const char* const roman_map[ROMAN_NUM][2] PROGMEM = {\
{a0,a1},\
{ba0,ba1},\
{bb0,bb1},\
{be0,be1},\
{bi0,bi1},\
{bo0,bo1},\
{bu0,bu1},\
{bya0,bya1},\
{bye0,bye1},\
{byi0,byi1},\
{byo0,byo1},\
{byu0,byu1},\
{cha0,cha1},\
{che0,che1},\
{chi0,chi1},\
{cho0,cho1},\
{chu0,chu1},\
{da0,da1},\
{dd0,dd1},\
{de0,de1},\
{dha0,dha1},\
{dhe0,dhe1},\
{dhi0,dhi1},\
{dho0,dho1},\
{dhu0,dhu1},\
{di0,di1},\
{dja0,dja1},\
{dji0,dji1},\
{djo0,djo1},\
{dju0,dju1},\
{do0,do1},\
{du0,du1},\
{dva0,dva1},\
{dve0,dve1},\
{dvi0,dvi1},\
{dvu0,dvu1},\
{dwa0,dwa1},\
{dwe0,dwe1},\
{dwi0,dwi1},\
{dwo0,dwo1},\
{dwu0,dwu1},\
{dya0,dya1},\
{dye0,dye1},\
{dyi0,dyi1},\
{dyo0,dyo1},\
{dyu0,dyu1},\
{e0,e1},\
{fa0,fa1},\
{fe0,fe1},\
{ff0,ff1},\
{fi0,fi1},\
{fo0,fo1},\
{fu0,fu1},\
{fya0,fya1},\
{fyo0,fyo1},\
{fyu0,fyu1},\
{ga0,ga1},\
{ge0,ge1},\
{gg0,gg1},\
{gi0,gi1},\
{go0,go1},\
{gu0,gu1},\
{gwa0,gwa1},\
{gwe0,gwe1},\
{gwi0,gwi1},\
{gwo0,gwo1},\
{gya0,gya1},\
{gye0,gye1},\
{gyi0,gyi1},\
{gyo0,gyo1},\
{gyu0,gyu1},\
{ha0,ha1},\
{he0,he1},\
{hh0,hh1},\
{hi0,hi1},\
{ho0,ho1},\
{hu0,hu1},\
{hwa0,hwa1},\
{hwe0,hwe1},\
{hwi0,hwi1},\
{hwo0,hwo1},\
{hwya0,hwya1},\
{hwyo0,hwyo1},\
{hwyu0,hwyu1},\
{hya0,hya1},\
{hye0,hye1},\
{hyi0,hyi1},\
{hyo0,hyo1},\
{hyu0,hyu1},\
{i0,i1},\
{ja0,ja1},\
{ji0,ji1},\
{jj0,jj1},\
{jo0,jo1},\
{ju0,ju1},\
{jya0,jya1},\
{jyu0,jyu1},\
{jyo0,jyo1},\
{ka0,ka1},\
{ke0,ke1},\
{ki0,ki1},\
{kk0,kk1},\
{ko0,ko1},\
{ku0,ku1},\
{kua0,kua1},\
{kue0,kue1},\
{kui0,kui1},\
{kuo0,kuo1},\
{kwa0,kwa1},\
{kwe0,kwe1},\
{kwi0,kwi1},\
{kwo0,kwo1},\
{kya0,kya1},\
{kye0,kye1},\
{kyi0,kyi1},\
{kyo0,kyo1},\
{kyu0,kyu1},\
{ma0,ma1},\
{me0,me1},\
{mi0,mi1},\
{mm0,mm1},\
{mo0,mo1},\
{mu0,mu1},\
{mwa0,mwa1},\
{mwe0,mwe1},\
{mwi0,mwi1},\
{mwo0,mwo1},\
{mya0,mya1},\
{mye0,mye1},\
{myi0,myi1},\
{myo0,myo1},\
{myu0,myu1},\
{nn0,nn1},\
{na0,na1},\
{ne0,ne1},\
{ni0,ni1},\
{no0,no1},\
{nu0,nu1},\
{nwa0,nwa1},\
{nwe0,nwe1},\
{nwi0,nwi1},\
{nwo0,nwo1},\
{nya0,nya1},\
{nye0,nye1},\
{nyi0,nyi1},\
{nyo0,nyo1},\
{nyu0,nyu1},\
{o0,o1},\
{pa0,pa1},\
{pe0,pe1},\
{pi0,pi1},\
{po0,po1},\
{pp0,pp1},\
{pu0,pu1},\
{pwa0,pwa1},\
{pwe0,pwe1},\
{pwi0,pwi1},\
{pwo0,pwo1},\
{pya0,pya1},\
{pye0,pye1},\
{pyi0,pyi1},\
{pyo0,pyo1},\
{pyu0,pyu1},\
{qa0,qa1},\
{qe0,qe1},\
{qi0,qi1},\
{qo0,qo1},\
{qu0,qu1},\
{ra0,ra1},\
{re0,re1},\
{ri0,ri1},\
{ro0,ro1},\
{rr0,rr1},\
{ru0,ru1},\
{rwa0,rwa1},\
{rwe0,rwe1},\
{rwi0,rwi1},\
{rwo0,rwo1},\
{rya0,rya1},\
{rye0,rye1},\
{ryi0,ryi1},\
{ryo0,ryo1},\
{ryu0,ryu1},\
{sa0,sa1},\
{se0,se1},\
{sha0,sha1},\
{shi0,shi1},\
{sho0,sho1},\
{shu0,shu1},\
{si0,si1},\
{so0,so1},\
{ss0,ss1},\
{su0,su1},\
{swa0,swa1},\
{swe0,swe1},\
{swi0,swi1},\
{swo0,swo1},\
{swu0,swu1},\
{sya0,sya1},\
{sye0,sye1},\
{syi0,syi1},\
{syo0,syo1},\
{syu0,syu1},\
{ta0,ta1},\
{te0,te1},\
{tha0,tha1},\
{the0,the1},\
{thi0,thi1},\
{tho0,tho1},\
{thu0,thu1},\
{ti0,ti1},\
{tja0,tja1},\
{tji0,tji1},\
{tjo0,tjo1},\
{tju0,tju1},\
{to0,to1},\
{tsa0,tsa1},\
{tse0,tse1},\
{tsi0,tsi1},\
{tso0,tso1},\
{tsu0,tsu1},\
{tt0,tt1},\
{tu0,tu1},\
{tva0,tva1},\
{tve0,tve1},\
{tvi0,tvi1},\
{tvu0,tvu1},\
{twa0,twa1},\
{twe0,twe1},\
{twi0,twi1},\
{two0,two1},\
{twu0,twu1},\
{tya0,tya1},\
{tye0,tye1},\
{tyi0,tyi1},\
{tyo0,tyo1},\
{tyu0,tyu1},\
{u0,u1},\
{va0,va1},\
{ve0,ve1},\
{vi0,vi1},\
{vo0,vo1},\
{vu0,vu1},\
{vvu0,vvu1},\
{vya0,vya1},\
{vyo0,vyo1},\
{vyu0,vyu1},\
{wa0,wa1},\
{we0,we1},\
{wha0,wha1},\
{wi0,wi1},\
{wo0,wo1},\
{ww0,ww1},\
{xa0,xa1},\
{xe0,xe1},\
{xi0,xi1},\
{xo0,xo1},\
{xtu0,xtu1},\
{xu0,xu1},\
{xxa0,xxa1},\
{xxe0,xxe1},\
{xxi0,xxi1},\
{xxo0,xxo1},\
{xxu0,xxu1},\
{xxwa0,xxwa1},\
{xxya0,xxya1},\
{xxyo0,xxyo1},\
{xxyu0,xxyu1},\
{xya0,xya1},\
{xyo0,xyo1},\
{xyu0,xyu1},\
{ya0,ya1},\
{ye0,ye1},\
{yo0,yo1},\
{yu0,yu1},\
{yy0,yy1},\
{za0,za1},\
{ze0,ze1},\
{zi0,zi1},\
{zo0,zo1},\
{zu0,zu1},\
{zwa0,zwa1},\
{zwe0,zwe1},\
{zwi0,zwi1},\
{zwo0,zwo1},\
{zwu0,zwu1},\
{zya0,zya1},\
{zye0,zye1},\
{zyi0,zyi1},\
{zyo0,zyo1},\
{zyu0,zyu1},\
{zz0,zz1}};
