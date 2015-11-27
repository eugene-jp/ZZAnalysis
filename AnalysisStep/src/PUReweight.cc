/** \file
 *
 *  Boris' weights from https://mangano.web.cern.ch/mangano/dropBox/puRW_v4.txt (as of September 24, 2012)
 *  Boris' weights from https://mangano.web.cern.ch/mangano/dropBox/puRW_v3.txt (as of June 24, 2012)
 *
 *  $Date: 2013/06/11 15:02:50 $
 *  $Revision: 1.15 $
 */

#include "../interface/PUReweight.h"

#include <iostream>
#include <cstdlib>

float PUReweight::weight(int MC, int target, float input) {

  TH1F* h;
  
  if (theType == RUN2ANALYSIS) {
    if        (MC==2011&&target==2011) {
      h = hT2011;
    } else if (MC==2012&&target==2012) {
      h = hTPuToLegacy13;
    } else if (MC==2015&&target==2015) {
      h = hTPuTo2015;
    } else{
      std::cout << "ERROR: PUReweight: " << MC << " " << target << std::endl;
      abort();
    }
        
  } else if (theType == LEGACY) {
    if        (MC==2011&&target==2011) {
      h = hT2011;
    } else if (MC==2012&&target==2012) {
      h = hTPuToLegacy13;
    } else{
      std::cout << "ERROR: PUReweight: " << MC << " " << target << std::endl;
      abort();
    }
        
  } else if (theType == MORIOND) {
    if        (MC==2011&&target==2011) {
      h = hT2011;
    } else if (MC==2012&&target==2012) {
      h = hTPuToMoriond13;
    } else{
      std::cout << "ERROR: PUReweight: " << MC << " " << target << std::endl;
      abort();
    }
        
  } else if (theType == HCP) {
    if        (MC==2011&&target==2011) {
      h = hT2011;
    } else if (MC==2012&&target==2012) {
      h = hTPuV10ToHcp53X; 
      // FIXME: for 52X samples one should use hTPuV07ToHcp53X
    } else{
      std::cout << "ERROR: PUReweight: " << MC << " " << target << std::endl;
      abort();
    }    

  } else if (theType==OLDICHEP) {
    if (input<0 || input>239) return 1.;

    if        (MC==2011&&target==2011) {
      if(input>50) return 1.;
      h= hT2011;

    } else if (MC==2012&&target==2012) {
      h= hT2012;

    } else if (MC==2011&&target==2012) {
      if(input>50) return 1.;
      h= hT2011To2012;

    } else{
      std::cout << "ERROR: PUReweight: " << MC << " " << target << std::endl;
      abort();
    }

  } else if (theType == ICHEP) {
    if        (MC==2011&&target==2011) {
      h = hT2011;
    } else if (MC==2012&&target==2012) {
      h = hTPuV10ToIchep53X;
    } else{
      std::cout << "ERROR: PUReweight: " << MC << " " << target << std::endl;
      abort();
    }    

  } else {

    return 0;
  }

  return h->GetBinContent(h->FindBin(input));
  
}


PUReweight::PUReweight(Type type) : 
  theType(type) {
  
  //--- WEIGHTS USED FOR ICHEP 

  // True2012
  hT2012 = new TH1F("hT2012","hT2012",240,0.,80.);  
  { 
    float w[240];
    w[0]= 1;
    w[1]= 1;
    w[2]= 0.222451;
    w[3]= 0.0658851;
    w[4]= 1;
    w[5]= 1;
    w[6]= 0.150902;
    w[7]= 0.202205;
    w[8]= 1;
    w[9]= 1;
    w[10]= 1.50116;
    w[11]= 2.79375;
    w[12]= 0.198341;
    w[13]= 0.246893;
    w[14]= 0.28116;
    w[15]= 0.449377;
    w[16]= 0.553276;
    w[17]= 1.48919;
    w[18]= 2.15249;
    w[19]= 3.62415;
    w[20]= 4.33041;
    w[21]= 3.57192;
    w[22]= 4.99603;
    w[23]= 7.79303;
    w[24]= 8.04276;
    w[25]= 8.05557;
    w[26]= 12.9364;
    w[27]= 9.9036;
    w[28]= 14.6975;
    w[29]= 13.3387;
    w[30]= 10.9734;
    w[31]= 12.6077;
    w[32]= 11.5617;
    w[33]= 10.8107;
    w[34]= 14.5043;
    w[35]= 17.8497;
    w[36]= 11.8817;
    w[37]= 9.6805;
    w[38]= 12.2255;
    w[39]= 10.1117;
    w[40]= 10.2482;
    w[41]= 11.5398;
    w[42]= 9.35737;
    w[43]= 9.90259;
    w[44]= 9.19216;
    w[45]= 7.57377;
    w[46]= 7.94847;
    w[47]= 7.15578;
    w[48]= 5.63016;
    w[49]= 5.35972;
    w[50]= 5.05791;
    w[51]= 3.35313;
    w[52]= 3.60582;
    w[53]= 3.35256;
    w[54]= 2.49496;
    w[55]= 2.28219;
    w[56]= 2.21227;
    w[57]= 1.76362;
    w[58]= 1.68533;
    w[59]= 1.62149;
    w[60]= 1.34263;
    w[61]= 1.30646;
    w[62]= 1.21918;
    w[63]= 1.10347;
    w[64]= 1.08544;
    w[65]= 1.0251;
    w[66]= 0.907123;
    w[67]= 0.905997;
    w[68]= 0.869217;
    w[69]= 0.816708;
    w[70]= 0.76043;
    w[71]= 0.714367;
    w[72]= 0.679723;
    w[73]= 0.665294;
    w[74]= 0.609956;
    w[75]= 0.586386;
    w[76]= 0.548999;
    w[77]= 0.521088;
    w[78]= 0.4929;
    w[79]= 0.453545;
    w[80]= 0.44546;
    w[81]= 0.406266;
    w[82]= 0.378486;
    w[83]= 0.347898;
    w[84]= 0.337097;
    w[85]= 0.313674;
    w[86]= 0.291392;
    w[87]= 0.283346;
    w[88]= 0.25272;
    w[89]= 0.244178;
    w[90]= 0.228673;
    w[91]= 0.211327;
    w[92]= 0.19084;
    w[93]= 0.179408;
    w[94]= 0.169234;
    w[95]= 0.157131;
    w[96]= 0.143818;
    w[97]= 0.140968;
    w[98]= 0.124021;
    w[99]= 0.118273;
    w[100]= 0.109751;
    w[101]= 0.0977754;
    w[102]= 0.0967206;
    w[103]= 0.0870401;
    w[104]= 0.0826372;
    w[105]= 0.0746777;
    w[106]= 0.0698592;
    w[107]= 0.0656062;
    w[108]= 0.0601853;
    w[109]= 0.057892;
    w[110]= 0.0517871;
    w[111]= 0.0512109;
    w[112]= 0.0465423;
    w[113]= 0.0403982;
    w[114]= 0.0443631;
    w[115]= 0.0399185;
    w[116]= 0.0338933;
    w[117]= 0.0354274;
    w[118]= 0.0310775;
    w[119]= 0.0261122;
    w[120]= 0.0280878;
    w[121]= 0.0264014;
    w[122]= 0.021299;
    w[123]= 0.0245197;
    w[124]= 0.0221076;
    w[125]= 0.0189236;
    w[126]= 0.0202148;
    w[127]= 0.0177248;
    w[128]= 0.0163634;
    w[129]= 0.0188307;
    w[130]= 0.0144512;
    w[131]= 0.0134599;
    w[132]= 0.0143315;
    w[133]= 0.0130668;
    w[134]= 0.0108666;
    w[135]= 0.0162516;
    w[136]= 0.0126035;
    w[137]= 0.0102154;
    w[138]= 0.0154442;
    w[139]= 0.00959973;
    w[140]= 0.0106827;
    w[141]= 0.0146624;
    w[142]= 0.0155156;
    w[143]= 0.00761674;
    w[144]= 0.0187999;
    w[145]= 0.0135013;
    w[146]= 0.0160794;
    w[147]= 0.0180586;
    w[148]= 0.00905508;
    w[149]= 0.00869858;
    w[150]= 0.0193968;
    w[151]= 0.0209201;
    w[152]= 0.0084405;
    w[153]= 0.0407657;
    w[154]= 0.0109116;
    w[155]= 0.0262218;
    w[156]= 0.0104767;
    w[157]= 1;
    w[158]= 1;
    w[159]= 1;
    w[160]= 1;
    w[161]= 0.00658031;
    w[162]= 0.0051814;
    w[163]= 1;
    w[164]= 1;
    w[165]= 1;
    w[166]= 1;
    w[167]= 1;
    w[168]= 1;
    w[169]= 1;
    w[170]= 1;
    w[171]= 1;
    w[172]= 1;
    w[173]= 1;
    w[174]= 1;
    w[175]= 1;
    w[176]= 1;
    w[177]= 1;
    w[178]= 1;
    w[179]= 1;
    w[180]= 1;
    w[181]= 1;
    w[182]= 1;
    w[183]= 1;
    w[184]= 1;
    w[185]= 1;
    w[186]= 1;
    w[187]= 1;
    w[188]= 1;
    w[189]= 1;
    w[190]= 1;
    w[191]= 1;
    w[192]= 1;
    w[193]= 1;
    w[194]= 1;
    w[195]= 1;
    w[196]= 1;
    w[197]= 1;
    w[198]= 1;
    w[199]= 1;
    w[200]= 1;
    w[201]= 1;
    w[202]= 1;
    w[203]= 1;
    w[204]= 1;
    w[205]= 1;
    w[206]= 1;
    w[207]= 1;
    w[208]= 1;
    w[209]= 1;
    w[210]= 1;
    w[211]= 1;
    w[212]= 1;
    w[213]= 1;
    w[214]= 1;
    w[215]= 1;
    w[216]= 1;
    w[217]= 1;
    w[218]= 1;
    w[219]= 1;
    w[220]= 1;
    w[221]= 1;
    w[222]= 1;
    w[223]= 1;
    w[224]= 1;
    w[225]= 1;
    w[226]= 1;
    w[227]= 1;
    w[228]= 1;
    w[229]= 1;
    w[230]= 1;
    w[231]= 1;
    w[232]= 1;
    w[233]= 1;
    w[234]= 1;
    w[235]= 1;
    w[236]= 1;
    w[237]= 1;
    w[238]= 1;
w[239]= 1;
    for(int k=0;k<240;k++){
      hT2012->SetBinContent(k+1,w[k]);
    } 
  }
  

  // True2011
  hT2011 = new TH1F("hT2011","hT2011",50,0.,50.);
  {
    float w[50];
    w[0]= 0.212929;
    w[1]= 0.0208114;
    w[2]= 0.0584048;
    w[3]= 0.538898;
    w[4]= 1.357;
    w[5]= 1.49913;
    w[6]= 1.42247;
    w[7]= 1.35904;
    w[8]= 1.29946;
    w[9]= 1.27925;
    w[10]= 1.37845;
    w[11]= 1.71246;
    w[12]= 1.5291;
    w[13]= 1.35234;
    w[14]= 1.22215;
    w[15]= 1.0155;
    w[16]= 1.01137;
    w[17]= 0.395465;
    w[18]= 0.230984;
    w[19]= 0.109883;
    w[20]= 0.0433739;
    w[21]= 0.0111497;
    w[22]= 0.00408801;
    w[23]= 0.00115678;
    w[24]= 0.000365505;
    w[25]= 0.000112391;
    w[26]= 3.83894e-05;
    w[27]= 1.60651e-05;
    w[28]= 4.81412e-06;
    w[29]= 1.39717e-06;
    w[30]= 1.92368e-06;
    w[31]= 4.10748e-06;
    w[32]= 2.33157e-05;
    w[33]= 4.0181e-05;
    w[34]= 4.87786e-05;
    w[35]= 0.00194128;
    w[36]= 8.97414e-05;
    w[37]= 1;
    w[38]= 1;
    w[39]= 0.000162709;
    w[40]= 1;
    w[41]= 1;
    w[42]= 1;
    w[43]= 1;
    w[44]= 1;
    w[45]= 1;
    w[46]= 1;
    w[47]= 1;
    w[48]= 1;
    w[49]= 1;
 
    for(int k=0;k<50;k++){
      hT2011->SetBinContent(k+1,w[k]);
    }
  }  

  // True2011to2012
  hT2011To2012 = new TH1F("hT2011To2012","hT2011To2012",50,0.,50.);
  {
    float w[50];

    w[0]= 0.000443112;
    w[1]= 0.000248044;
    w[2]= 0.000273111;
    w[3]= 0.00109511;
    w[4]= 0.00195699;
    w[5]= 0.00480746;
    w[6]= 0.027013;
    w[7]= 0.074795;
    w[8]= 0.166231;
    w[9]= 0.309545;
    w[10]= 0.577657;
    w[11]= 1.12488;
    w[12]= 1.36899;
    w[13]= 1.56925;
    w[14]= 1.89846;
    w[15]= 2.20828;
    w[16]= 3.14112;
    w[17]= 1.87712;
    w[18]= 1.97062;
    w[19]= 2.07067;
    w[20]= 2.17791;
    w[21]= 1.7176;
    w[22]= 2.10953;
    w[23]= 2.0805;
    w[24]= 2.29498;
    w[25]= 2.42189;
    w[26]= 2.80303;
    w[27]= 3.94091;
    w[28]= 3.67917;
    w[29]= 2.26081;
    w[30]= 2.99726;
    w[31]= 3.76553;
    w[32]= 11.285;
    w[33]= 10.2781;
    w[34]= 6.73407;
    w[35]= 148.182;
    w[36]= 3.88144;
    w[37]= 1;
    w[38]= 1;
    w[39]= 1.48128;
    w[40]= 1;
    w[41]= 1;
    w[42]= 1;
    w[43]= 1;
    w[44]= 1;
    w[45]= 1;
    w[46]= 1;
    w[47]= 1;
    w[48]= 1;
    w[49]= 1;
 
    for(int k=0;k<50;k++){
      hT2011To2012->SetBinContent(k+1,w[k]);
    }
  }


  //--- Updated weights (Fall 2012)

  //52XMC (pileup V07) weighted to 52X ICHEP data
  hTPuV07ToIchep52X = new TH1F("hTPuV07ToIchep52X","hTPuV07ToIchep52X",60,0.,60.);
  {
    float w[60] = {
      2.59113e-07,
      1.77107e-05,
      0.0263017,
      1.66396,
      0.16421,
      0.754166,
      2.84622,
      5.57103,
      8.66558,
      11.5716,
      11.8712,
      12.8102,
      10.3421,
      8.91019,
      7.614,
      6.10397,
      4.52745,
      3.26031,
      2.39558,
      1.83297,
      1.47821,
      1.26728,
      1.14716,
      1.06707,
      0.98066,
      0.860877,
      0.708281,
      0.539789,
      0.37652,
      0.237298,
      0.1338,
      0.0671236,
      0.0299236,
      0.0118723,
      0.00420968,
      0.00134235,
      0.000389563,
      0.000104892,
      2.69214e-05,
      6.79674e-06,
      1.73307e-06,
      4.52553e-07,
      1.21124e-07,
      3.29924e-08,
      9.10616e-09,
      2.53998e-09,
      7.16146e-10,
      2.03786e-10,
      5.84308e-11,
      1.68192e-11,
      4.8434e-12,
      1.38959e-12,
      3.96112e-13,
      1.11358e-13,
      3.17245e-14,
      5.34916e-15,
      0,
      0,
      0,
      0};
                
    for(int k=0;k<60;k++){
      hTPuV07ToIchep52X->SetBinContent(k+1,w[k]);
    }           
  }

  //53XMC (pileup V07) weighted to 53X HCP data
  hTPuV07ToHcp53X = new TH1F("hTPuV07ToHcp53X","hTPuV07ToHcp53X",60,0.,60.);
  {
    float w[60] = {
      0.0447136,     
      0.11785,       
      0.23825,
      1.08447,
      0.102575,
      0.454605,
      1.79761,
      4.00271,
      6.83281,
      9.83701,
      10.7966,
      12.2356,
      10.0247,
      8.49395,
      7.1125,
      5.69527,
      4.31256,
      3.19305,
      2.42035,
      1.91666,
      1.58485,
      1.36297,
      1.21166,
      1.09466,
      0.978941,
      0.84653,
      0.699235,
      0.548996,
      0.408673,
      0.288194,
      0.193367,
      0.124653,
      0.0781124,
      0.0479268,
      0.0287763,
      0.0167744,
      0.00941834,
      0.00507877,
      0.00264364,
      0.00134612,
      0.000682678,
      0.000351412,
      0.0001864,
      0.00010259,
      5.87818e-05,
      3.5033e-05,
      2.17116e-05,
      1.39777e-05,
      9.36123e-06,
      6.53328e-06,
      4.76598e-06,
      3.64139e-06,
      2.92018e-06,
      2.4602e-06,
      2.17291e-06,
      2.01107e-06,
      1.94392e-06,
      1.9598e-06,
      2.0583e-06,
      2.24895e-06};
                
    for(int k=0;k<60;k++){
      hTPuV07ToHcp53X->SetBinContent(k+1,w[k]);
    }           
  }
        
        
        
        
        
  //53XMC (pileup V10) weighted to 53X ICHEP data
  hTPuV10ToIchep53X = new TH1F("hTPuV10ToIchep53X","hTPuV10ToIchep53X",60,0.,60.);
  {
    float w[60] = {
      2.35693e-06,
      7.51928e-05,
      0.0263529,
      0.609947,
      0.737917,
      1.29365,
      0.994503,
      0.85454,
      1.01559,
      1.33243,
      1.72454,
      2.01264,
      2.00573,
      1.80333,
      1.56328,
      1.37452,
      1.24753,
      1.16481,
      1.11738,
      1.09701,
      1.08843,
      1.08796,
      1.09768,
      1.10763,
      1.09328,
      1.0339,
      0.92408,
      0.771537,
      0.59283,
      0.41266,
      0.256892,
      0.14188,
      0.0692543,
      0.029902,
      0.0114564,
      0.00391383,
      0.00120625,
      0.000341485,
      9.09127e-05,
      2.34008e-05,
      5.95438e-06,
      1.5122e-06,
      3.82094e-07,
      9.51794e-08,
      2.32205e-08,
      5.51698e-09,
      1.27267e-09,
      2.84346e-10,
      6.12799e-11,
      1.26731e-11,
      2.50309e-12,
      4.69797e-13,
      8.35153e-14,
      1.39452e-14,
      2.24718e-15,
      2.03841e-16,
      0,
      0,
      0,
      0};
                
    for(int k=0;k<60;k++){
      hTPuV10ToIchep53X->SetBinContent(k+1,w[k]);
    }           
  }
        
  //53XMC (pileup V10) weighted to 53X HCP data
  hTPuV10ToHcp53X = new TH1F("hTPuV10ToHcp53X ","hTPuV10ToHcp53X ",60,0.,60.);
  {
    float w[60] = {
      0.409409,
      0.527276,
      0.39328,
      0.507892,
      0.48029,
      0.787701,
      0.632356,
      0.618033,
      0.806089,
      1.14018,
      1.5788,
      1.93507,
      1.957,
      1.73004,
      1.46737,
      1.28278,
      1.18189,
      1.13388,
      1.12578,
      1.14415,
      1.16048,
      1.1618,
      1.15318,
      1.13405,
      1.09239,
      1.01915,
      0.914837,
      0.786744,
      0.644879,
      0.502039,
      0.371688,
      0.263586,
      0.18067,
      0.120472,
      0.0780184,
      0.0486113,
      0.0289039,
      0.0163367,
      0.00879674,
      0.00456046,
      0.0023098,
      0.00115977,
      0.000583207,
      0.000294815,
      0.000149865,
      7.62892e-05,
      3.87537e-05,
      1.96105e-05,
      9.87744e-06,
      4.95418e-06,
      2.47913e-06,
      1.23919e-06,
      6.19751e-07,
      3.10125e-07,
      1.54934e-07,
      7.71425e-08,
      3.8182e-08,
      1.87455e-08,
      9.10765e-09,
      9.19802e-09};
                
    for(int k=0;k<60;k++){
      hTPuV10ToHcp53X->SetBinContent(k+1,w[k]);
    }           
  }

  //53XMC weighted to 53X Moriond data
  hTPuToMoriond13 = new TH1F("hTPuToMoriond13 ","hTPuToMoriond13 ",60,0.,60.);
  {

    float w[60]={
      0.252009,
      0.327042,
      0.335502,
      0.352291,
      0.324698,
      0.582754,
      0.455286,
      0.441035,
      0.607629,
      0.930019,
      1.3379,
      1.69521,
      1.74041,
      1.54857,
      1.32193,
      1.15754,
      1.07437,
      1.05152,
      1.07105,
      1.11463,
      1.15493,
      1.17791,
      1.18516,
      1.17815,
      1.1528,
      1.10551,
      1.03652,
      0.948613,
      0.844304,
      0.728083,
      0.607242,
      0.489813,
      0.381766,
      0.287126,
      0.207777,
      0.144102,
      0.0957851,
      0.0611744,
      0.0376984,
      0.0226007,
      0.0133203,
      0.00782018,
      0.00464555,
      0.00284065,
      0.00182028,
      0.00123555,
      0.000891118,
      0.000679799,
      0.000543107,
      0.000449514,
      0.000382089,
      0.000331034,
      0.000290923,
      0.00025824,
      0.000230472,
      0.000206238,
      0.000184523,
      0.000164717,
      0.000146364,
      0.000271878};

    for(int k=0;k<60;k++){
      hTPuToMoriond13->SetBinContent(k+1,w[k]);
    }           
  }
  
  //53XMC weighted to 53X Legacy data
  hTPuToLegacy13 = new TH1F("hTPuToLegacy13 ","hTPuToLegacy13 ",60,0.,60.);
  {
    Float_t w[60]={
      0.242421,
      0.314567,
      0.328551,
      0.341325,
      0.311977,
      0.560934,
      0.443155,
      0.444942,
      0.625725,
      0.940482,
      1.33114,
      1.67986,
      1.7303,
      1.54809,
      1.32353,
      1.15668,
      1.07105,
      1.04548,
      1.06319,
      1.10733,
      1.14954,
      1.17563,
      1.188,
      1.18718,
      1.16671,
      1.121,
      1.04977,
      0.956974,
      0.84729,
      0.727003,
      0.603974,
      0.485796,
      0.377733,
      0.283343,
      0.204364,
      0.14118,
      0.0934506,
      0.059445,
      0.0365081,
      0.0218306,
      0.012844,
      0.00753269,
      0.00447223,
      0.00273386,
      0.00175157,
      0.00118879,
      0.000857334,
      0.000653996,
      0.000522478,
      0.000432433,
      0.000367567,
      0.000318451,
      0.000279865,
      0.000248423,
      0.000221711,
      0.000198398,
      0.000177509,
      0.000158456,
      0.000140801,
      0.000261544};

    for(int k=0;k<60;k++){
      hTPuToLegacy13->SetBinContent(k+1,w[k]);
    }           
  }

  //74XMC weighted to 2015 data
  hTPuTo2015 = new TH1F("hTPuTo2015 ","hTPuTo2015 ",50,0.,50.);
  {
    Double_t w[50] = {
 123.399,
 154.47,
 108.554,
 32.763,
 18.2968,
 3.40335,
 2.02491,
 2.63973,
 3.51624,
 3.42417,
 3.09104,
 2.72272,
 2.13664,
 1.42202,
 0.791307,
 0.369041,
 0.152811,
 0.0650246,
 0.0333021,
 0.0189518,
 0.00993272,
 0.00438741,
 0.00162793,
 0.000542239,
 0.000188182,
 8.05114e-05,
 4.39913e-05,
 2.86295e-05,
 2.0744e-05,
 1.56229e-05,
 1.11165e-05,
 6.71918e-06,
 3.28503e-06,
 1.34808e-06,
 4.93771e-07,
 1.67913e-07,
 5.39796e-08,
 1.65294e-08,
 4.83796e-09,
 1.35595e-09,
 3.64387e-10,
 9.39859e-11,
 2.32859e-11,
 5.54578e-12,
 1.27045e-12,
 2.8007e-13,
 1.47068e-13,
 4.36405e-14,
 3.97859e-14,
    };
    for(int k=0;k<50;k++){
      hTPuTo2015->SetBinContent(k+1,w[k]);
    }           

  }
}


PUReweight::~PUReweight() {
  delete hT2012;
  delete hT2011;
  delete hT2011To2012;
  
  delete hTPuV07ToIchep52X;
  delete hTPuV10ToIchep53X;
  delete hTPuV07ToHcp53X;
  delete hTPuV10ToHcp53X;
  delete hTPuToMoriond13;
  delete hTPuToLegacy13;
}

