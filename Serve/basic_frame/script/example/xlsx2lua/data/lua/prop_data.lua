local type = type
----------------------------------------
local modname="prop_data"
local M={}
_G[modname]=M
package.loaded[modname]=M
if setfenv then
	setfenv(1, M) -- for 5.1
else
	_ENV = M -- for 5.2
end
----------------------------------------
if not (type(data_prop)=="table") then
	data_prop = {}
end

data_prop =
{
	[1]= {id=1,bj=0,lvl=0,nz=0,sb=0,tl=100,xl=5000,zs=0,},
	[2]= {id=2,bj=0.1,lvl=1,nz=2000,sb=0.1,tl=101,xl=5100,zs=100,},
	[3]= {id=3,bj=0.2,lvl=2,nz=3988,sb=0.2,tl=101,xl=5200,zs=100,},
	[4]= {id=4,bj=0.3,lvl=3,nz=5964,sb=0.3,tl=102,xl=5300,zs=100,},
	[5]= {id=5,bj=0.4,lvl=4,nz=7928,sb=0.4,tl=102,xl=5400,zs=100,},
	[6]= {id=6,bj=0.5,lvl=5,nz=9880,sb=0.5,tl=103,xl=5500,zs=100,},
	[7]= {id=7,bj=0.6,lvl=6,nz=11820,sb=0.6,tl=103,xl=5600,zs=100,},
	[8]= {id=8,bj=0.7,lvl=7,nz=13748,sb=0.7,tl=104,xl=5700,zs=100,},
	[9]= {id=9,bj=0.8,lvl=8,nz=15664,sb=0.8,tl=104,xl=5800,zs=100,},
	[10]= {id=10,bj=0.9,lvl=9,nz=17568,sb=0.9,tl=105,xl=5900,zs=100,},
	[11]= {id=11,bj=1,lvl=10,nz=19460,sb=1,tl=105,xl=6000,zs=100,},
	[12]= {id=12,bj=1.1,lvl=11,nz=21340,sb=1.1,tl=106,xl=6100,zs=100,},
	[13]= {id=13,bj=1.2,lvl=12,nz=23208,sb=1.2,tl=106,xl=6200,zs=100,},
	[14]= {id=14,bj=1.3,lvl=13,nz=25064,sb=1.3,tl=107,xl=6300,zs=100,},
	[15]= {id=15,bj=1.4,lvl=14,nz=26908,sb=1.4,tl=107,xl=6400,zs=100,},
	[16]= {id=16,bj=1.5,lvl=15,nz=28740,sb=1.5,tl=108,xl=6500,zs=100,},
	[17]= {id=17,bj=1.6,lvl=16,nz=30560,sb=1.6,tl=108,xl=6600,zs=100,},
	[18]= {id=18,bj=1.7,lvl=17,nz=32368,sb=1.7,tl=109,xl=6700,zs=100,},
	[19]= {id=19,bj=1.8,lvl=18,nz=34164,sb=1.8,tl=109,xl=6800,zs=100,},
	[20]= {id=20,bj=1.9,lvl=19,nz=35948,sb=1.9,tl=110,xl=6900,zs=100,},
	[21]= {id=21,bj=2,lvl=20,nz=37720,sb=2,tl=110,xl=7000,zs=100,},
	[22]= {id=22,bj=2.1,lvl=21,nz=39480,sb=2.1,tl=111,xl=7100,zs=100,},
	[23]= {id=23,bj=2.2,lvl=22,nz=41228,sb=2.2,tl=111,xl=7200,zs=100,},
	[24]= {id=24,bj=2.3,lvl=23,nz=42964,sb=2.3,tl=112,xl=7300,zs=100,},
	[25]= {id=25,bj=2.4,lvl=24,nz=44688,sb=2.4,tl=112,xl=7400,zs=100,},
	[26]= {id=26,bj=2.5,lvl=25,nz=46400,sb=2.5,tl=113,xl=7500,zs=100,},
	[27]= {id=27,bj=2.6,lvl=26,nz=48100,sb=2.6,tl=113,xl=7600,zs=100,},
	[28]= {id=28,bj=2.7,lvl=27,nz=49788,sb=2.7,tl=114,xl=7700,zs=100,},
	[29]= {id=29,bj=2.8,lvl=28,nz=51464,sb=2.8,tl=114,xl=7800,zs=100,},
	[30]= {id=30,bj=2.9,lvl=29,nz=53128,sb=2.9,tl=115,xl=7900,zs=100,},
	[31]= {id=31,bj=3,lvl=30,nz=54780,sb=3,tl=115,xl=8000,zs=100,},
	[32]= {id=32,bj=3.1,lvl=31,nz=56420,sb=3.1,tl=116,xl=8100,zs=100,},
	[33]= {id=33,bj=3.2,lvl=32,nz=58048,sb=3.2,tl=116,xl=8200,zs=100,},
	[34]= {id=34,bj=3.3,lvl=33,nz=59664,sb=3.3,tl=117,xl=8300,zs=100,},
	[35]= {id=35,bj=3.4,lvl=34,nz=61268,sb=3.4,tl=117,xl=8400,zs=100,},
	[36]= {id=36,bj=3.5,lvl=35,nz=62860,sb=3.5,tl=118,xl=8500,zs=100,},
	[37]= {id=37,bj=3.6,lvl=36,nz=64440,sb=3.6,tl=118,xl=8600,zs=100,},
	[38]= {id=38,bj=3.7,lvl=37,nz=66008,sb=3.7,tl=119,xl=8700,zs=100,},
	[39]= {id=39,bj=3.8,lvl=38,nz=67564,sb=3.8,tl=119,xl=8800,zs=100,},
	[40]= {id=40,bj=3.9,lvl=39,nz=69108,sb=3.9,tl=120,xl=8900,zs=100,},
	[41]= {id=41,bj=4,lvl=40,nz=70640,sb=4,tl=120,xl=9000,zs=100,},
	[42]= {id=42,bj=4.1,lvl=41,nz=72160,sb=4.1,tl=121,xl=9100,zs=100,},
	[43]= {id=43,bj=4.2,lvl=42,nz=73668,sb=4.2,tl=121,xl=9200,zs=100,},
	[44]= {id=44,bj=4.3,lvl=43,nz=75164,sb=4.3,tl=122,xl=9300,zs=100,},
	[45]= {id=45,bj=4.4,lvl=44,nz=76648,sb=4.4,tl=122,xl=9400,zs=100,},
	[46]= {id=46,bj=4.5,lvl=45,nz=78120,sb=4.5,tl=123,xl=9500,zs=100,},
	[47]= {id=47,bj=4.6,lvl=46,nz=79580,sb=4.6,tl=123,xl=9600,zs=100,},
	[48]= {id=48,bj=4.7,lvl=47,nz=81028,sb=4.7,tl=124,xl=9700,zs=100,},
	[49]= {id=49,bj=4.8,lvl=48,nz=82464,sb=4.8,tl=124,xl=9800,zs=100,},
	[50]= {id=50,bj=4.9,lvl=49,nz=83888,sb=4.9,tl=125,xl=9900,zs=100,},
	[51]= {id=51,bj=5,lvl=50,nz=85300,sb=5,tl=125,xl=10000,zs=100,},
	[52]= {id=52,bj=5.1,lvl=51,nz=86700,sb=5.1,tl=126,xl=10100,zs=100,},
	[53]= {id=53,bj=5.2,lvl=52,nz=88088,sb=5.2,tl=126,xl=10200,zs=100,},
	[54]= {id=54,bj=5.3,lvl=53,nz=89464,sb=5.3,tl=127,xl=10300,zs=100,},
	[55]= {id=55,bj=5.4,lvl=54,nz=90828,sb=5.4,tl=127,xl=10400,zs=100,},
	[56]= {id=56,bj=5.5,lvl=55,nz=92180,sb=5.5,tl=128,xl=10500,zs=100,},
	[57]= {id=57,bj=5.6,lvl=56,nz=93520,sb=5.6,tl=128,xl=10600,zs=100,},
	[58]= {id=58,bj=5.7,lvl=57,nz=94848,sb=5.7,tl=129,xl=10700,zs=100,},
	[59]= {id=59,bj=5.8,lvl=58,nz=96164,sb=5.8,tl=129,xl=10800,zs=100,},
	[60]= {id=60,bj=5.9,lvl=59,nz=97468,sb=5.9,tl=130,xl=10900,zs=100,},
	[61]= {id=61,bj=6,lvl=60,nz=98760,sb=6,tl=130,xl=11000,zs=100,},
	[62]= {id=62,bj=6.1,lvl=61,nz=100040,sb=6.1,tl=131,xl=11100,zs=100,},
	[63]= {id=63,bj=6.2,lvl=62,nz=101308,sb=6.2,tl=131,xl=11200,zs=100,},
	[64]= {id=64,bj=6.3,lvl=63,nz=102564,sb=6.3,tl=132,xl=11300,zs=100,},
	[65]= {id=65,bj=6.4,lvl=64,nz=103808,sb=6.4,tl=132,xl=11400,zs=100,},
	[66]= {id=66,bj=6.5,lvl=65,nz=105040,sb=6.5,tl=133,xl=11500,zs=100,},
	[67]= {id=67,bj=6.6,lvl=66,nz=106260,sb=6.6,tl=133,xl=11600,zs=100,},
	[68]= {id=68,bj=6.7,lvl=67,nz=107468,sb=6.7,tl=134,xl=11700,zs=100,},
	[69]= {id=69,bj=6.8,lvl=68,nz=108664,sb=6.8,tl=134,xl=11800,zs=100,},
	[70]= {id=70,bj=6.9,lvl=69,nz=109848,sb=6.9,tl=135,xl=11900,zs=100,},
	[71]= {id=71,bj=7,lvl=70,nz=111020,sb=7,tl=135,xl=12000,zs=100,},
	[72]= {id=72,bj=7.1,lvl=71,nz=112180,sb=7.1,tl=136,xl=12100,zs=100,},
	[73]= {id=73,bj=7.2,lvl=72,nz=113328,sb=7.2,tl=136,xl=12200,zs=100,},
	[74]= {id=74,bj=7.3,lvl=73,nz=114464,sb=7.3,tl=137,xl=12300,zs=100,},
	[75]= {id=75,bj=7.4,lvl=74,nz=115588,sb=7.4,tl=137,xl=12400,zs=100,},
	[76]= {id=76,bj=7.5,lvl=75,nz=116700,sb=7.5,tl=138,xl=12500,zs=100,},
	[77]= {id=77,bj=7.6,lvl=76,nz=117800,sb=7.6,tl=138,xl=12600,zs=100,},
	[78]= {id=78,bj=7.7,lvl=77,nz=118888,sb=7.7,tl=139,xl=12700,zs=100,},
	[79]= {id=79,bj=7.8,lvl=78,nz=119964,sb=7.8,tl=139,xl=12800,zs=100,},
	[80]= {id=80,bj=7.9,lvl=79,nz=121028,sb=7.9,tl=140,xl=12900,zs=100,},
	[81]= {id=81,bj=8,lvl=80,nz=122080,sb=8,tl=140,xl=13000,zs=100,},
	[82]= {id=82,bj=8.1,lvl=81,nz=123120,sb=8.1,tl=141,xl=13100,zs=100,},
	[83]= {id=83,bj=8.2,lvl=82,nz=124148,sb=8.2,tl=141,xl=13200,zs=100,},
	[84]= {id=84,bj=8.3,lvl=83,nz=125164,sb=8.3,tl=142,xl=13300,zs=100,},
	[85]= {id=85,bj=8.4,lvl=84,nz=126168,sb=8.4,tl=142,xl=13400,zs=100,},
	[86]= {id=86,bj=8.5,lvl=85,nz=127160,sb=8.5,tl=143,xl=13500,zs=100,},
	[87]= {id=87,bj=8.6,lvl=86,nz=128140,sb=8.6,tl=143,xl=13600,zs=100,},
	[88]= {id=88,bj=8.7,lvl=87,nz=129108,sb=8.7,tl=144,xl=13700,zs=100,},
	[89]= {id=89,bj=8.8,lvl=88,nz=130064,sb=8.8,tl=144,xl=13800,zs=100,},
	[90]= {id=90,bj=8.9,lvl=89,nz=131008,sb=8.9,tl=145,xl=13900,zs=100,},
	[91]= {id=91,bj=9,lvl=90,nz=131940,sb=9,tl=145,xl=14000,zs=100,},
	[92]= {id=92,bj=9.1,lvl=91,nz=132860,sb=9.1,tl=146,xl=14100,zs=100,},
	[93]= {id=93,bj=9.2,lvl=92,nz=133768,sb=9.2,tl=146,xl=14200,zs=100,},
	[94]= {id=94,bj=9.3,lvl=93,nz=134664,sb=9.3,tl=147,xl=14300,zs=100,},
	[95]= {id=95,bj=9.4,lvl=94,nz=135548,sb=9.4,tl=147,xl=14400,zs=100,},
	[96]= {id=96,bj=9.5,lvl=95,nz=136420,sb=9.5,tl=148,xl=14500,zs=100,},
	[97]= {id=97,bj=9.6,lvl=96,nz=137280,sb=9.6,tl=148,xl=14600,zs=100,},
	[98]= {id=98,bj=9.7,lvl=97,nz=138128,sb=9.7,tl=149,xl=14700,zs=100,},
	[99]= {id=99,bj=9.8,lvl=98,nz=138964,sb=9.8,tl=149,xl=14800,zs=100,},
	[100]= {id=100,bj=9.9,lvl=99,nz=139788,sb=9.9,tl=150,xl=14900,zs=100,},
	[101]= {id=101,bj=10,lvl=100,nz=140600,sb=10,tl=150,xl=15000,zs=100,},
}
----------------------------------------------
return M
