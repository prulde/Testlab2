#include <lib/lr1.h>
#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include <fstream>
#include <iterator>
#include <sstream>

// Подробнее https://google.github.io/googletest/reference/testing.html

std::vector<int> read_file(std::string path)
{
	std::vector<int> res;
	std::ifstream file_in(path);
	if (!file_in)
	{
	}
	int number;
	while (file_in >> number)
	{
		res.push_back(number);
	}
	file_in.close();

	return res;
}

class LR1T : public ::testing::Test
{

};

TEST_F(LR1T, SPath1)
{
	std::vector<int> in = {482954982, 2002623384, 1073394366, 209623520, -776211159, 1052430588, -716243639, 1259230478, 1341886454, -45083621, 1790340256, 1223722837, 1414342933, -1084793771, -2069837757, -800291609, 1444317036, -913814783, -1907869211, 123093134, 412554094, -1263171614, -770025968, -37128708, -709530773, 1165394466, -1687847822, -899781044, 1009008087, 632806843, 926771917, -611491785, 2013127785, -479929083, -580128530, -1515598737, 561791554, 2032674366, 1527030826, -205639332, 1096228348, -154428665, -584559552, 768898373, 1194383848, 890144869, -699479128, -1910851648, 1577562969, -1793350304, -22988979, -1079788754, 672152474, 1080896236, 224899990, 1664024889, -1356479194, 291232425, 1889949079, -1290377973, 1686849282, -607146895, -1391734981, -1519863339, 972164269, 60640974, -2136771123, 1677450545, -184456953, -1524599944, 1965416060, -2126340493, -162012117, 1334059104, 729127691, 571487888, -342481013, -1672117216, -83947676, 302414991, -1440709325, -736619334, 821494196, -792124621, 1094675820, -1285623769, 1378531416, 654379855, 49629563, 1553584018, 99616533, 617564026, 1746333190, 822221366, -1158926892, -1216745158, -545381970, -1131819253, 1324633250, 1566409268, -2071997265, 929905275, 147634023, -2057887132, 465542610, -1431090624, -9770956, 1754346363, -1667601862, 740305747, -989201516, 757506727, -78652730, 798447494, -1443856006, -371021488, -996575216, -1215374855, -799574007, 926354861, 1505722381, -1404097775, -316874930, 1821821652, -299029307, 34136830, -366146246, -356142198, 348811469, 1631693012, -833589897, 828852697, -252920423, -1885798450, -257150363, 813982098, -1686891845, 1640691820, 1482680291, -412305838, 854986017, 189491640, 1162075512, -896279960, -1867614654, -572089447, -1986768739, -52907793, 2122925685, -488770191, -809093770, 1601800374, -170071932, 1837264597, 291159637, -1860284498, 1107920338, -1972113796, 1104662202, 1750844683, 1800788915, -424952103, 1526079333, -471035122, 1220833889, 826161281, 480311093, 2049388943, 956379192, 887626825, 1422967048, -150338822, -1190801707, 799218078, -1695529813, 1639517137, -1055025863, 1622088142, -1369954091, 695031317, 1418108695, -1285591009, 1595173657, -2050222813, -405917230, -1382196826, 37193194, 1503095901, -778405441, -1172975902, -1138343768, -2057523, 1377081847, 414982297, -1094074882, 1262891996, 1082238671, 1194112518, -89421837, -1934898085, -1268133720, -907170801, -1344077601, -399787446, -1056133670, -240411835, 638870876, -593989272, -1714577689, 820610014, 2139611308, 804080420, 13416333, 539120886, -1579655707, -373123674, 2098850602, 2107505761, 724636457, -1994642798, 1762652225, -364427577, 1709957998, 401139665, 373053399, -92710031, -1062513952, -1560984190, 1206711720, -15370060, 1272112873, -766192441, -255177249, -1449175394, 1538122159, -1029937419, 609936070, -1801742307, -1409758599, 973098072, -759723947, 1149229650, -139761915, 740532114, -1919030264, 1460823206, 771397753, -1005428232, -1779682101, 1726034859, 314571674, -1455303082, 395674857, 830147545, -2146048907, 227788026, 8737206, 1399993244, -1330027751, -1325167022, 1266940177, 1106021162, 1479064653, -1890109926, -945218034, 1073678382, 827912172, -1008985034, -433675174, -52386166, 1208168473, -398002643, -1823863460, 1113229846, -1348312836, -2116256940, 1761199635, -4693011, -206906728, -463792841, 772588442, -1549957689, -252066776, -470718919, 1727739276, -1656635984, -103552623, -882368039, 190705369, 2124039036, -1772692952, 928853481, -1984765626, 702855620, 352165363, 594349782, 696099940, -2097973273, -690796499, -1668611264, 1887281569, 459257558, 87323796, 910298775, 494276883, 1923978975, -189831140, 1700888898, 1657820847, -86827586, 238511166, -1629296416, -1963569169, -820757990, -399131059, 801448731, 1010089626, -763081438, -422549157, 617493675, -989687317, 50046347, 1794886846, -1736674031, 1014318836, 1239718375, -811537820, -785614380, -1646848774, 1526699496, 1632860654, 496133991, -2055680893, 1380124284, 2124642384, -768255152, 309029903, -871136595, 1666393230, -1871943299, -650064055, 1490243191, 1504990963, -1327577920, 1040179125, 1404849192, -1833413241, 972873966, 182565230, 976934040, 2099980940, 717624092, -1122880179, 1308498689, -1635991096, 1486219807, -1482931668, -321622180, 1528738531, -960733370, -1332568409, 81963921, -430111306, 1682381681, -1734156351, 900573330, -72805441, 446550639, -813636007, 438144787, -555549757, -1834398148, 1231251467, 816566511, 1399068798, 239422262, -1339814513, 315650931, 1087716809, 1092742323, 581285009, -1689134355, 443279767, -1081704364, 548115927, 1820483922, -1113882823, 600686697, 1249032203, -432913694, 856807848, -2009025125, 1572366687, -2058955008, -22859156, -1609328703, 795900939, -427719598, -1526037116, -1147870681, -957386808, 1859349399, 1878023606, -255147044, 1439068126, -1416514029, 2076646863, -1134658084, 40811163, 1679345551, -1441274061, 369581197, -1486372757, -1216958161, -49658351, -25240848, -867346984, -929676053, 1741088779, -606852003, -1870565151, -1645701894, 1656055981, 843596008, 35940978, 911162994, -15833828, -1162698837, -1055980689, 1908209841, -1762637474, 1727452393, -2049986986, -773760117, -14394646, 159833915, 459039791, -491293091, 1501004697, 2048265801, -1510009326, 1735513242, 429287583, 229333293, -1199443004, -790152724, -293513155, -955213468, 1125760366, 1871221330, -178511692, -1492210306, -1180117869, -1297970911, 2101088189, -210751317, -264217685, 1541846551, 1319969579, 96666484, -587574355, 489268931, 1996470013, 1734194198, 1213279697, -1912162349, 137505602, 793973223, -1063246121, 502328959, 166434975, -453226894, 151243614, -1599375554, 2146147196, 1676040641, 975548819, 1562845745, -191608670, 729806754, 670877723, -1007305489, 1792267888, 1537887569, 1163416474, 521726138, -872197740, 865748364, 1855738862, -1051479989, -1988142652, 770184892, -97458051, -480684261, 121556723, 1940208508, -9459762, 1404144399, 751933099, -262430090, 754151493, 2046821651, 1662156304, -748701922, -812348437, -1801378698, 1118298105, -833860544, 487280586, -378870966, 2059306836, -394498889, -888478286, 1620663650, -1327334392, 1765801292, -1579966252, -1788459265, -290587192, 1307054040, 2107198051, 852200791, 1641742333, 994096179, -1039103028, -62098897, 1711762277, 1231562950, 1088004253, -505892437, 1617457174, -198953259, 2101178631, 2133600043, -1518325275, -1775032219, 435102057, 914344797, -1371348066, -1410528383, -1304048640, -891698390, -2061244676, 1064222937, 799203791, -185007322, 2077334444, -1508997487, 708039634, 53667908, -2021919051, -1102809351, 1055386197, -1671173921, -1566681629, 796514747, 860713857, -1199232391, 1521628090, 1829224448, -1215867564, -1916005280, 1891615038, 1376411534, -1294507461, -2082378112, -1327949863, 1361701786, -92516737, 1107779745, -614701213, 828611812, 1015563832, -68080872, -1498508089, 307330908, 1237631717, 955628868, 2070015750, -93348057, -543557733, -9058329, -1362131257, -1264281254, -1135641419, 1740010373, 1133570330, -1704084430, -1735736581, 864484229, -1931533046, 236161936, -715880330, -1761986190, -226072326, -996796070, 676983989, 329343463, -193241068, -738480736, -293876220, 1744344211, 1197414997, 442974850, -155705393, 339513938, -1615358971, -468026483, 1861708436, 394288603, -1346810037, -1267269476, -1842846978, -1665522932, 291018912, -206702697, 2145847313, 695872100, 796633834, 1344857536, -1554597023, 392463794, 2024687398, 1777222662, 1203169851, -1869274677, 370214009, 1985282866, 1299607336, -83409614, 1266703209, -2046330473, -2146184114, 2075878509, -523460592, 1909282662, -1749258863, 695490868, 1089147513, -332304480, 840258662, -1189457606, -1273198988, 389697519, 1480477320, 858547795, -1780264032, -1594689436, -1318319017, -588616999, -29243479, 1926439424, -218470422, -788051878, -528185833, -1830950244, 1639555641, -1967362410, -560955969, -103145817, 1879575558, -1649508278, 1843425334, -285013089, -325517479, 373319828, 383174637, -1338336111, -903765248, -1294301220, 670469061, 2037362086, 1805871806, 1019368823, 668759018, -1895572969, -1409736843, 1879294275, -1234761612, 1927950625, -868289780, 869221487, -180658679, -44820014, 902672251, -928827240, 1205660354, 597204027, 1496605550, 1749061306, 2026740485, 521293053, 1600221820, 172990114, -601558619, -1303776738, 1300577774, 2104932191, -642771938, 1411759188, -1187984243, 410810222, -2011514207, 127893346, -114191762, 579650980, 1884223892, -114596326, 976555119, -446562929, 1956045509, -193534025, -854227831, 1765597526, -437262692, 1366984613, -625506146, 119673802, 218656995, 1131611829, 1654811753, -550879939, -1159968193, -123788831, -84000799, 1606553174, 1603808614, -1322715668, 963697068, -1107798661, -684548158, -1300045810, 1933330943, 1593938551, 1536044281, -1302831912, 411974954, -1539120053, -831559775, -1671409740, -1324532446, 2136052093, 1491411637, -489554945, 424187106, 1292118375, -2058412466, 1217112960, -1801391316, -875681925, -1670180768, -739806925, 338953860, 575775787, 636288155, -518729343, -129279290, 1754864564, -1478071336, 2093507572, -189834184, 764527657, 182435879, -695126537, 2103561028, -2065246680, 752608417, -2033741252, 1324445228, -2011251994, -1006014344, 484141619, -87225085, 611280376, 1755608681, -1982960689, -2035593378, 1092874347, -2066126116, 582907773, 1499432735, -956702805, 146126088, 1646048323, -1698173319, -1260538361, -3220609, 856621474, 1449352532, 769292327, -668822846, -1324728606, -858889196, 1568867689, 2052108451, -1177921355, 771132176, 2016392816, -1116973259, 1406022286, -636934940, -472474202, 897261358, -1200479865, -96204828, 922768758, -1782042748, -830462370, 1826581732, -578775529, -220430949, -42839646, -1125217548, 909189074, 513735056, -1537885217, 1092900003, 1395514180, -985777894, 1386726296, -1912436538, -551419599, 1860454419, -1924662037, 1226012970, 1893186057, 388181172, -1831984264, -618218168, 1835929225, -36869133, 1948766591, 1805499826, -871924533, 797952253, 1798574969, -1067695040, -778253682, -1766240285, -836421333, -519330202, 261785059, -1572737844, 1114501934, 291722246, -314240792, -1503720771, 494744152, 443373167, 751031962, -238776092, 1576160693, 327052698, -578253792, 1750867807, 2045393653, -1514321007, -1323392899, 1297551455, 1305790662, -826914926, 1118832487, 1752039798, -1449772118, -1629534517, -1443452473, 1222433170, 1189770911, -991747508, -482521178, 207497566, -1379396216, -1344861503, 1520057026, -1119526007, -1745070504, 1604505680, -333511901, 61419725, 220785, 579178972, -324627106, -591832946, 2108107798, -1878722951, 1157037971, 1112639967, -878955223, 1804879930, -941678948, -1596156769, -1497646793, -1075242991, -1449532556, -219331393, -1477323774, 173827839, -1060878764, 340200113, -2007932884, -365493903, 686157701, -1514031073, 1477831064, 1902604290, -560731212, 2092473142, 1310160625, 338509789, -1654581525, -1235191680, 2001439204, -1491491176, -79475843, 286532532, -1823943548, -1303305387, -1526903585, 1411777059, -1367580768, 1394072871, 1181702836, -1181588523, 1396033150, -336395850, -806439550, -634486692, 1608735857, 1577025356, 238975191, 1395889220, -207175435, -360199190, -1181422891, -345117429, -3622213, -2102524312, -1077102977, -177304026, -205328992, -618866832, 696054235, 164623397, -349291074, 1710883383, -944070340, 2077904933, 1858782460, 512286673, 1550040122, 1891921819, -309426341, 1204941577, -1946115178, -1822536484, 1877952608, 1694539238, 196879042, -1650932708, 1462592439, 1863468172, -1955385999, -908615472, 322131786, 528645196, -1776765732, -575858335, 580917817, -1424639568, -2021777020, 216126315, -1376508500, -462572545, 829612739, -22959959, 969622328, -2074814586, 566856321, 906186168, -1609987638, 1555893632, 2077603491, 2131570981, 1890598458, 151956845, -1452402172, 588490302, -1605206662, 953707469, 109162935, 609769133, -1126864598, -1868902060, -2056612216, -854977458, -163668813, -1751238490, 900504195, 1734755771, -1790736921, -854763238, 193369301, -678466853, 2064246311, 953035215, -1732064992, -2143481472, 1623710341, 36046366, 2036874028, 876985980, 1495608518, -826327068, -1332464976, -1074962069, -589662131, -141352280, -153694327, -511182988, -1248985903, 1895767200, 453954596, -172713139, -1846455986, -480944055};
	Res output = countAndSum(in);
	EXPECT_EQ(output.errors.size(), 1);
	EXPECT_EQ(output.errors[0], oversized);
}

TEST_F(LR1T, SPath2)
{
	std::vector<int> in = {2147483647, 2147483647};

	Res output = countAndSum(in);

	EXPECT_EQ(output.errors.size(), 1);
	EXPECT_EQ(output.errors[0], overflow);
}

TEST_F(LR1T, SPath3)
{
	std::vector<int> in = {};

	Res output = countAndSum(in);

	std::vector<int> outputTest = {};
	if (!output.sizeChanged)
		EXPECT_EQ(output.min, INT_MAX);
	EXPECT_EQ(output.result, outputTest);
}

TEST_F(LR1T, SPath4)
{
	std::vector<int> in = {-2147483647, -2147483647};

	Res output = countAndSum(in);

	EXPECT_EQ(output.errors.size(), 1);
	EXPECT_EQ(output.errors[0], overflow);
}

TEST_F(LR1T, SPath5)
{
	std::vector<int> in = {1073741826};

	Res output = countAndSum(in);

	EXPECT_EQ(output.errors.size(), 1);
	EXPECT_EQ(output.errors[0], overflow);
}

TEST_F(LR1T, SPath6)
{
	std::vector<int> in = {-1073741827};

	Res output = countAndSum(in);

	EXPECT_EQ(output.errors.size(), 1);
	EXPECT_EQ(output.errors[0], overflow);
}

TEST_F(LR1T, SPath8)
{
	std::vector<int> in = {10737418};

	Res output = countAndSum(in);

	EXPECT_EQ(output.result.size(), 1);
	EXPECT_EQ(output.min, in[0] + in[0]);
}

TEST_F(LR1T, SPath10range156)
{
	std::vector<int> in = read_file("../../../../data/path10r156.txt");
	std::vector<int> out = read_file("../../../../data/path10r156res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}

TEST_F(LR1T, SPath10range208)
{
	std::vector<int> in = read_file("../../../../data/path10r208.txt");
	std::vector<int> out = read_file("../../../../data/path10r208res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}

TEST_F(LR1T, SPath10range260)
{
	std::vector<int> in = read_file("../../../../data/path10r260.txt");
	std::vector<int> out = read_file("../../../../data/path10r260res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}

TEST_F(LR1T, SPath10range312)
{
	std::vector<int> in = read_file("../../../../data/path10r312.txt");
	std::vector<int> out = read_file("../../../../data/path10r312res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}

TEST_F(LR1T, SPath10range364)
{
	std::vector<int> in = read_file("../../../../data/path10r364.txt");
	std::vector<int> out = read_file("../../../../data/path10r364res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}

TEST_F(LR1T, SPath10range416)
{
	std::vector<int> in = read_file("../../../../data/path10r416.txt");
	std::vector<int> out = read_file("../../../../data/path10r416res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}

TEST_F(LR1T, SPath10range468)
{
	std::vector<int> in = read_file("../../../../data/path10r468.txt");
	std::vector<int> out = read_file("../../../../data/path10r468res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}

TEST_F(LR1T, SPath10range520)
{
	std::vector<int> in = read_file("../../../../data/path10r520.txt");
	std::vector<int> out = read_file("../../../../data/path10r520res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}

TEST_F(LR1T, SPath10range573)
{
	std::vector<int> in = read_file("../../../../data/path10r573.txt");
	std::vector<int> out = read_file("../../../../data/path10r573res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}

TEST_F(LR1T, SPath10range626)
{
	std::vector<int> in = read_file("../../../../data/path10r626.txt");
	std::vector<int> out = read_file("../../../../data/path10r626res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}

TEST_F(LR1T, SPath10range679)
{
	std::vector<int> in = read_file("../../../../data/path10r679.txt");
	std::vector<int> out = read_file("../../../../data/path10r679res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}

TEST_F(LR1T, SPath10range732)
{
	std::vector<int> in = read_file("../../../../data/path10r732.txt");
	std::vector<int> out = read_file("../../../../data/path10r732res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}

TEST_F(LR1T, SPath10range785)
{
	std::vector<int> in = read_file("../../../../data/path10r785.txt");
	std::vector<int> out = read_file("../../../../data/path10r785res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}


TEST_F(LR1T, SPath10range838)
{
	std::vector<int> in = read_file("../../../../data/path10r838.txt");
	std::vector<int> out = read_file("../../../../data/path10r838res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}

TEST_F(LR1T, SPath10range891)
{
	std::vector<int> in = read_file("../../../../data/path10r891.txt");
	std::vector<int> out = read_file("../../../../data/path10r891res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}

TEST_F(LR1T, SPath10range944)
{
	std::vector<int> in = read_file("../../../../data/path10r944.txt");
	std::vector<int> out = read_file("../../../../data/path10r944res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}

TEST_F(LR1T, SPath10range997)
{
	std::vector<int> in = read_file("../../../../data/path10r997.txt");
	std::vector<int> out = read_file("../../../../data/path10r997res.txt");
	Res output = countAndSum(in);
	EXPECT_EQ(output.result, out);
}

TEST_F(LR1T, KIbegin)
{
	std::vector<int> in = { -1858816376,
- 858775419,
536953433,
415759671,
549826788,
- 288050195,
- 738014828,
944056608,
- 948787325,
- 10190872,
- 12224567,
115356241,
- 322764382,
- 185427050,
- 1045043572,
- 126635443,
- 818764297,
749026972,
- 764896377
	};
	Res output = countAndSum(in);
	EXPECT_EQ(output.min, -1871040943);
}

TEST_F(LR1T, KImid)
{
	std::vector<int> in = { -1001329711,
879945867,
937759885,
229506197,
- 889869444,
844017938,
- 864733033,
- 60838666,
745927765,
17455918,
- 191218999,
132557486,
675845853,
737146307,
- 354008736,
347327088,
391992787,
- 480163850,
- 505620406,
- 619748173,
	};
	Res output = countAndSum(in);
	EXPECT_EQ(output.min, -1243878180);
}

TEST_F(LR1T, KIend)
{
	std::vector<int> in = { -858816376,
-858775419,
536953433,
415759671,
549826788,
-288050195,
-738014828,
944056608,
-948787325,
-1019092872,
12224567,
115356241,
-322764382,
-185427050,
-1045043572,
-126635443,
-818764297,
749026972,
-764896377,

	};
	Res output = countAndSum(in);
	EXPECT_EQ(output.min, -2038185744
	);
}