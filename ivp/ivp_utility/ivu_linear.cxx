// Copyright (C) Ipion Software GmbH 1999-2000. All rights reserved.

#ifndef _WIN32
#	pragma implementation "ivu_linear.hxx"
#	pragma implementation "ivu_linear_software.hxx"
#	pragma implementation "ivu_linear_double.hxx"
#	pragma implementation "ivu_linear_ps2.hxx"
#	pragma implementation "ivu_linear_macros.hxx"
#	pragma implementation "ivu_matrix_macros.hxx"
#endif

/**** INCLUDES *****/
#include <ivp_physics.hxx>
#include <ivu_matrix_macros.hxx>

#if defined(PSXII) || defined(GEKKO)
#	include <string.h>
#elif defined(LINUX) || defined(WIN32) || defined(SGI) || (defined(__MWERKS__) && defined(__POWERPC__)) || defined(GEKKO)
#	include <memory.h>
#	include <string.h>
#endif


#include <ivu_float.hxx>
#include <ivu_string.cxx>


IVP_DOUBLE get_float(){
	return p_atof(p_str_tok(NULL, IVP_WHITESPACE));
}


IVP_FLOAT IVP_Inline_Math::isqrt_float(IVP_FLOAT quad){
    return hk_Math::fast_sqrt_inv(quad);
}

IVP_DOUBLE IVP_Inline_Math::isqrt_double(IVP_DOUBLE quad){
    return hk_Math::fast_sqrt_invd(quad);
}

IVP_DOUBLE IVP_Inline_Math::lut_asintbl[513] = { -1.5707963267948966, -1.5197264560314263, -1.4985174926593343, -1.482205415678339, -1.4684217872733267, -1.4562499321048734, -1.4452200672019901, -1.4350533154266485, -1.4255680955912222, -1.4166383631913866, -1.408172403711216, -1.4001010220440966, -1.392370491767887, -1.3849381109044885, -1.3777692752815924, -1.3708354805254257, -1.3641129161545034, -1.3575814505144228, -1.351223881458963, -1.3450253724097492, -1.3389730206590216, -1.3330555218905482, -1.327262905945597, -1.3215863261764098, -1.3160178896787678, -1.3105505191098419, -1.305177839195445, -1.2998940827420802, -1.2946940122084394, -1.2895728538006095, -1.2845262417311667, -1.2795501707903483, -1.2746409557633807, -1.2697951965240317, -1.2650097478635554, -1.2602816932930638, -1.2556083221981027, -1.2509871098357856, -1.2464156997539193, -1.2418918882831431, -1.2374136108109892, -1.2329789295938562, -1.2285860229014032, -1.224233175319532, -1.219918769064298, -1.2156412761808129, -1.2113992515193144, -1.2071913263957739, -1.2030162028571552, -1.1988726484822345, -1.1947594916580093, -1.190675617279507, -1.1866199628274243, -1.182591514783713, -1.1785893053500958, -1.1746124094387056, -1.170659941907669, -1.1667310550175956, -1.1628249360876755, -1.1589408053324606, -1.1550779138624891, -1.1512355418337277, -1.147412996732405, -1.1436096117832142, -1.1398247444700966, -1.1360577751599108, -1.1323081058202624, -1.12857515882362, -1.1248583758306099, -1.1211572167460555, -1.1174711587419341, -1.113799695341957, -1.1101423355629718, -1.1064986031088053, -1.1028680356125653, -1.099250183923755, -1.0956446114368792, -1.0920508934585005, -1.0884686166099509, -1.0848973782631486, -1.081336786007164, -1.0777864571433842, -1.0742460182072748, -1.070715104514921, -1.0671933597326433, -1.0636804354681346, -1.0601759908816701, -1.0566796923160524, -1.0531912129440515, -1.0497102324321936, -1.04623643661982, -1.042769517212434, -1.0393091714884022, -1.0358551020181488, -1.0324070163950427, -1.0289646269772186, -1.0255276506396362, -1.0220958085357115, -1.01866882586791, -1.0152464316667165, -1.0118283585774408, -1.0084143426543453, -1.0050041231616107, -1.001597442380684, -0.9981940454235811, -0.9947936800517301, -0.9913960964999756, -0.98800104730537, -0.9846082871404083, -0.9812175726503699, -0.9778286622944519, -0.9744413161903867, -0.9710552959622569, -0.9676703645912235, -0.9642862862688993, -0.9609028262531101, -0.9575197507257853, -0.9541368266527419, -0.9507538216451181, -0.9473705038222295, -0.9439866416756179, -0.9406020039340748, -0.9372163594294193, -0.9338294769628139, -0.93044112517141, -0.927051072395107, -0.923659086543219, -0.9202649349608362, -0.9168683842946733, -0.9134692003581938, -0.9100671479957956, -0.9066619909458471, -0.9032534917023519, -0.8998414113750248, -0.8964255095475515, -0.8930055441338031, -0.8895812712317677, -0.8861524449749605, -0.8827188173810577, -0.8792801381975017, -0.875836154743807, -0.8723866117502943, -0.8689312511929629, -0.8654698121242048, -0.8620020304990469, -0.8585276389965976, -0.8550463668363565, -0.8515579395890309, -0.848062078981481, -0.844558502695404, -0.8410469241593385, -0.8375270523335535, -0.8339985914873578, -0.8304612409683426, -0.8269146949630394, -0.8233586422484449, -0.819792765933832, -0.8162167431922284, -0.8126302449809052, -0.8090329357501806, -0.8054244731397877, -0.8018045076620182, -0.7981726823707898, -0.7945286325157336, -0.790871985180333, -0.7872023589030734, -0.7835193632804954, -0.7798225985509537, -0.7761116551578082, -0.7723861132906638, -0.7686455424031841, -0.7648895007058839, -0.7611175346321817, -0.7573291782758602, -0.7535239527979349, -0.7497013658007657, -0.7458609106670734, -0.7420020658613234, -0.738124294190734, -0.7342270420229172, -0.7303097384569202, -0.7263717944441344, -0.7224126018552356, -0.7184315324889698, -0.7144279370182132, -0.710401143868312, -0.7063504580222446, -0.7022751597466106, -0.6981745032318897, -0.6940477151397502, -0.6898939930494806, -0.6857125037948001, -0.6815023816814135, -0.6772627265746614, -0.6729926018454851, -0.668691032161655, -0.6643570011097718, -0.659989448631936, -0.6555872682591487, -0.6511493041214307, -0.6466743477122958, -0.6421611343825323, -0.6376083395351928, -0.6330145744901967, -0.6283783819829585, -0.6236982312568463, -0.6189725127039982, -0.6141995320029076, -0.6093775036941232, -0.6045045441271993, -0.5995786637024748, -0.5945977583200986, -0.5895595999356362, -0.5844618261062156, -0.5793019283930297, -0.5740772394645246, -0.5687849187190687, -0.5634219362154246, -0.5579850546628164, -0.5524708091784283, -0.5468754844670037, -0.5411950890126215, -0.5354253257938186, -0.5295615589363589, -0.5235987755982989, -0.5175315422333763, -0.511353954192911, -0.5050595773925062, -0.4986413804733018, -0.49209165550872647, -0.4854019248198378, -0.47856283082856493, -0.4715640050471065, -0.46439391120104295, -0.4570396560100902, -0.4494867591543905, -0.44171887121625775, -0.4337174245796306, -0.42546119689421064, -0.4169257589971522, -0.4080827679121598, -0.39889904873820403, -0.38933538361425024, -0.37934488588509746, -0.36887077316856504, -0.35784324602878925, -0.3461749945630322, -0.3337545234368926, -0.3204358578938943, -0.3060219299688337, -0.29023620658428523, -0.2726706075244549, -0.25268025514207865, -0.22913998754587428, -0.1997508402588858, -0.1581485485751356, 0.0, 0.1581485485751356, 0.1997508402588858, 0.22913998754587428, 0.25268025514207865, 0.2726706075244549, 0.29023620658428523, 0.3060219299688337, 0.3204358578938943, 0.3337545234368926, 0.3461749945630322, 0.35784324602878925, 0.36887077316856504, 0.37934488588509746, 0.38933538361425024, 0.39889904873820403, 0.4080827679121598, 0.4169257589971522, 0.42546119689421064, 0.4337174245796306, 0.44171887121625775, 0.4494867591543905, 0.4570396560100902, 0.46439391120104295, 0.4715640050471065, 0.47856283082856493, 0.4854019248198378, 0.49209165550872647, 0.4986413804733018, 0.5050595773925062, 0.511353954192911, 0.5175315422333763, 0.5235987755982989, 0.5295615589363589, 0.5354253257938186, 0.5411950890126215, 0.5468754844670037, 0.5524708091784283, 0.5579850546628164, 0.5634219362154246, 0.5687849187190687, 0.5740772394645246, 0.5793019283930297, 0.5844618261062156, 0.5895595999356362, 0.5945977583200986, 0.5995786637024748, 0.6045045441271993, 0.6093775036941232, 0.6141995320029076, 0.6189725127039982, 0.6236982312568463, 0.6283783819829585, 0.6330145744901967, 0.6376083395351928, 0.6421611343825323, 0.6466743477122958, 0.6511493041214307, 0.6555872682591487, 0.659989448631936, 0.6643570011097718, 0.668691032161655, 0.6729926018454851, 0.6772627265746614, 0.6815023816814135, 0.6857125037948001, 0.6898939930494806, 0.6940477151397502, 0.6981745032318897, 0.7022751597466106, 0.7063504580222446, 0.710401143868312, 0.7144279370182132, 0.7184315324889698, 0.7224126018552356, 0.7263717944441344, 0.7303097384569202, 0.7342270420229172, 0.738124294190734, 0.7420020658613234, 0.7458609106670734, 0.7497013658007657, 0.7535239527979349, 0.7573291782758602, 0.7611175346321817, 0.7648895007058839, 0.7686455424031841, 0.7723861132906638, 0.7761116551578082, 0.7798225985509537, 0.7835193632804954, 0.7872023589030734, 0.790871985180333, 0.7945286325157336, 0.7981726823707898, 0.8018045076620182, 0.8054244731397877, 0.8090329357501806, 0.8126302449809052, 0.8162167431922284, 0.819792765933832, 0.8233586422484449, 0.8269146949630394, 0.8304612409683426, 0.8339985914873578, 0.8375270523335535, 0.8410469241593385, 0.844558502695404, 0.848062078981481, 0.8515579395890309, 0.8550463668363565, 0.8585276389965976, 0.8620020304990469, 0.8654698121242048, 0.8689312511929629, 0.8723866117502943, 0.875836154743807, 0.8792801381975017, 0.8827188173810577, 0.8861524449749605, 0.8895812712317677, 0.8930055441338031, 0.8964255095475515, 0.8998414113750248, 0.9032534917023519, 0.9066619909458471, 0.9100671479957956, 0.9134692003581938, 0.9168683842946733, 0.9202649349608362, 0.923659086543219, 0.927051072395107, 0.93044112517141, 0.9338294769628139, 0.9372163594294193, 0.9406020039340748, 0.9439866416756179, 0.9473705038222295, 0.9507538216451181, 0.9541368266527419, 0.9575197507257853, 0.9609028262531101, 0.9642862862688993, 0.9676703645912235, 0.9710552959622569, 0.9744413161903867, 0.9778286622944519, 0.9812175726503699, 0.9846082871404083, 0.98800104730537, 0.9913960964999756, 0.9947936800517301, 0.9981940454235811, 1.001597442380684, 1.0050041231616107, 1.0084143426543453, 1.0118283585774408, 1.0152464316667165, 1.01866882586791, 1.0220958085357115, 1.0255276506396362, 1.0289646269772186, 1.0324070163950427, 1.0358551020181488, 1.0393091714884022, 1.042769517212434, 1.04623643661982, 1.0497102324321936, 1.0531912129440515, 1.0566796923160524, 1.0601759908816701, 1.0636804354681346, 1.0671933597326433, 1.070715104514921, 1.0742460182072748, 1.0777864571433842, 1.081336786007164, 1.0848973782631486, 1.0884686166099509, 1.0920508934585005, 1.0956446114368792, 1.099250183923755, 1.1028680356125653, 1.1064986031088053, 1.1101423355629718, 1.113799695341957, 1.1174711587419341, 1.1211572167460555, 1.1248583758306099, 1.12857515882362, 1.1323081058202624, 1.1360577751599108, 1.1398247444700966, 1.1436096117832142, 1.147412996732405, 1.1512355418337277, 1.1550779138624891, 1.1589408053324606, 1.1628249360876755, 1.1667310550175956, 1.170659941907669, 1.1746124094387056, 1.1785893053500958, 1.182591514783713, 1.1866199628274243, 1.190675617279507, 1.1947594916580093, 1.1988726484822345, 1.2030162028571552, 1.2071913263957739, 1.2113992515193144, 1.2156412761808129, 1.219918769064298, 1.224233175319532, 1.2285860229014032, 1.2329789295938562, 1.2374136108109892, 1.2418918882831431, 1.2464156997539193, 1.2509871098357856, 1.2556083221981027, 1.2602816932930638, 1.2650097478635554, 1.2697951965240317, 1.2746409557633807, 1.2795501707903483, 1.2845262417311667, 1.2895728538006095, 1.2946940122084394, 1.2998940827420802, 1.305177839195445, 1.3105505191098419, 1.3160178896787678, 1.3215863261764098, 1.327262905945597, 1.3330555218905482, 1.3389730206590216, 1.3450253724097492, 1.351223881458963, 1.3575814505144228, 1.3641129161545034, 1.3708354805254257, 1.3777692752815924, 1.3849381109044885, 1.392370491767887, 1.4001010220440966, 1.408172403711216, 1.4166383631913866, 1.4255680955912222, 1.4350533154266485, 1.4452200672019901, 1.4562499321048734, 1.4684217872733267, 1.482205415678339, 1.4985174926593343, 1.5197264560314263, 1.5707963267948966 };

IVP_DOUBLE IVP_Inline_Math::lut_asin(IVP_FLOAT r) {
    if (r >= 1.0f) return 1.5707963267948966;

    float xp = r * r * r * 256 + 256;

    int x0 = (int)xp;
    int x1 = x0 + 1;

    double y0 = lut_asintbl[x0];
    double y1 = lut_asintbl[x1];

    return y0 + ((y1 - y0) / (x1 - x0)) * (xp - x0);
}

IVP_DOUBLE IVP_Inline_Math::lut_acos(IVP_FLOAT r) { return 1.5707963267948966 - lut_asin(r); }

#if !defined(IVP_NO_DOUBLE)
void IVP_U_Point::set_interpolate(const IVP_U_Point *p0,const IVP_U_Point *p1, IVP_DOUBLE s)
{
    IVP_DOUBLE is = 1.0f - s;
    IVP_DOUBLE a = p0->k[0] * is;
    IVP_DOUBLE a2 = p1->k[0] * s;
    IVP_DOUBLE b = p0->k[1] * is;
    IVP_DOUBLE b2 = p1->k[1] * s; a += a2;
    IVP_DOUBLE c = p0->k[2] * is;
    IVP_DOUBLE c2 = p1->k[2] * s; b += b2;

    k[0] = a; k[1] = b; k[2] = c + c2;
}

void IVP_U_Point::set_interpolate(const IVP_U_Float_Point *p0,const IVP_U_Float_Point *p1, IVP_DOUBLE s)
{
    IVP_DOUBLE is = 1.0f - s;
    IVP_DOUBLE a = p0->k[0] * is;
    IVP_DOUBLE a2 = p1->k[0] * s;
    IVP_DOUBLE b = p0->k[1] * is;
    IVP_DOUBLE b2 = p1->k[1] * s; a += a2;
    IVP_DOUBLE c = p0->k[2] * is;
    IVP_DOUBLE c2 = p1->k[2] * s; b += b2;

    k[0] = a; k[1] = b; k[2] = c + c2;
}
#endif

void IVP_U_Float_Point::set_interpolate(const IVP_U_Float_Point *p0,const IVP_U_Float_Point *p1, IVP_DOUBLE s)
{
    IVP_DOUBLE is = 1.0f - s;
    IVP_DOUBLE a = p0->k[0] * is;
    IVP_DOUBLE a2 = p1->k[0] * s;
    IVP_DOUBLE b = p0->k[1] * is;
    IVP_DOUBLE b2 = p1->k[1] * s; a += a2;
    IVP_DOUBLE c = p0->k[2] * is;
    IVP_DOUBLE c2 = p1->k[2] * s; b += b2;

    k[0] = (IVP_FLOAT)a; k[1] = (IVP_FLOAT)b; k[2] = (IVP_FLOAT)(c + c2);
}

IVP_DOUBLE IVP_U_Float_Point::real_length()const{
    return IVP_Inline_Math::sqrtd(this->quad_length());
}

#if !defined(IVP_NO_DOUBLE)
IVP_DOUBLE IVP_U_Point::real_length()const{
    return IVP_Inline_Math::sqrtd(this->quad_length());
}


IVP_RETURN_TYPE IVP_U_Point::fast_normize(){
    IVP_DOUBLE length = this->quad_length();
    if (length< P_DOUBLE_EPS ) return IVP_FAULT;
    IVP_DOUBLE f = IVP_Fast_Math::isqrt(length,2);
    this->mult(f);
    return IVP_OK;
}

IVP_DOUBLE IVP_U_Point::real_length_plus_normize() {
    IVP_DOUBLE qlength = this->quad_length();
    if (qlength < P_DOUBLE_EPS ){
      //k[0] = 1.0; k[1] = 0; k[2] = 0;
      return 0.0;
    }
    IVP_DOUBLE f = IVP_Fast_Math::isqrt(qlength,3);
    this->mult(f);
    return f * qlength; //qlength * f;
}
#endif



IVP_DOUBLE IVP_U_Float_Point::real_length_plus_normize() {
    IVP_DOUBLE qlength = this->quad_length();
    if (qlength < P_DOUBLE_EPS ){
      //k[0] = 1.0; k[1] = 0; k[2] = 0;
      return 0.0f;
    }
    IVP_DOUBLE f = IVP_Fast_Math::isqrt(qlength,3);
    this->mult(f);
    return f * qlength; //qlength * f;
}


IVP_RETURN_TYPE IVP_U_Float_Point::fast_normize(){
    IVP_DOUBLE length = this->quad_length();
    if (length< P_DOUBLE_EPS ) return IVP_FAULT;
    IVP_DOUBLE f = IVP_Fast_Math::isqrt(length,2);
    this->mult(f);
    return IVP_OK;
}


IVP_RETURN_TYPE IVP_U_Float_Point::normize(){
    IVP_DOUBLE length = this->quad_length();
    if (length< P_DOUBLE_EPS ) return IVP_FAULT;
    IVP_DOUBLE f = IVP_Fast_Math::isqrt(length,2);
    this->mult(f);
    return IVP_OK;
}

#if !defined(IVP_NO_DOUBLE)
IVP_RETURN_TYPE IVP_U_Point::normize(){
    IVP_DOUBLE length = this->quad_length();
    if (length< P_DOUBLE_EPS ) return IVP_FAULT;
    IVP_DOUBLE f = IVP_Fast_Math::isqrt(length,3);
    this->mult(f);
    return IVP_OK;
}
#endif

void IVP_U_Float_Point::line_sqrt(){
    k[0] = IVP_Inline_Math::ivp_sqrtf(k[0]);
    k[1] = IVP_Inline_Math::ivp_sqrtf(k[1]);
    k[2] = IVP_Inline_Math::ivp_sqrtf(k[2]);
}

void IVP_U_Point::set_orthogonal_part(const IVP_U_Point *vector,const IVP_U_Point *normal_v) {
    IVP_DOUBLE part_direction=normal_v->dot_product(vector);
    this->add_multiple(vector,normal_v,-part_direction);
}

void IVP_U_Point::set_orthogonal_part(const IVP_U_Point *vector,const IVP_U_Float_Point *normal_v) {
    IVP_DOUBLE part_direction= vector->dot_product(normal_v);
    this->add_multiple(vector,normal_v,-part_direction);
}


void IVP_U_Float_Point::set_orthogonal_part(const IVP_U_Float_Point *vector,const IVP_U_Float_Point *normal_v) {
    IVP_DOUBLE part_direction= vector->dot_product(normal_v);
    this->add_multiple(vector,normal_v,-part_direction);
}

#if !defined(IVP_NO_DOUBLE)
void IVP_U_Point::calc_cross_product(const IVP_U_Point *v1,const IVP_U_Point *v2){
    inline_calc_cross_product(v1,v2);
}
#endif

void IVP_U_Float_Point::calc_cross_product(const IVP_U_Float_Point *v1,const IVP_U_Float_Point *v2)
{
    inline_calc_cross_product(v1,v2);
}

void IVP_U_Point::solve_quadratic_equation_fast(const IVP_U_Point *p){	// points stores quadratic equ. k[2] + x*k[1] * x^2 * k[0]
    if (IVP_Inline_Math::fabsd(p->k[0])<P_DOUBLE_EPS){ // linear equation
	k[0] = 0;
	if (IVP_Inline_Math::fabsd(p->k[1])> P_DOUBLE_EPS){
	    k[0] = -1.0f;	// no result
	    return;
	}
	k[1] = k[2] = - p->k[2] / p->k[1];
	return;
    }
    IVP_DOUBLE b2 = p->k[1] * p->k[1];
    IVP_DOUBLE ac4 = p->k[0] * p->k[2] * 4.0f;
    k[0] = b2 - ac4;
    if (k[0] > 0){
	IVP_DOUBLE i2a = .5f/p->k[0];
	IVP_DOUBLE sr = IVP_Fast_Math::sqrt(k[0]);
	IVP_DOUBLE l1 = (-p->k[1] - sr ) * i2a;
	IVP_DOUBLE l2 = (-p->k[1] + sr ) * i2a;
	k[1] = l1;
	k[2] = l2;
    }
}

void IVP_U_Point::solve_quadratic_equation_accurate(const IVP_U_Point *p){	// points stores quadratic equ. k[2] + x*k[1] * x^2 * k[0]
    if (IVP_Inline_Math::fabsd(p->k[0])< P_DOUBLE_EPS){ // linear equation
	k[0] = 0;
	if (IVP_Inline_Math::fabsd(p->k[1])<P_DOUBLE_EPS){
	    k[0] = -1.0f;	// no result
	    return;
	}
	k[1] = k[2] = - p->k[2] / p->k[1];
	return;
    }
    IVP_DOUBLE b2 = p->k[1] * p->k[1];
    IVP_DOUBLE ac4 = p->k[0] * p->k[2] * 4.0f;
    k[0] = b2 - ac4;
    if (k[0]>=0){
	IVP_DOUBLE i2a = .5f/p->k[0];
	IVP_DOUBLE sr = IVP_Inline_Math::sqrtd(k[0]);
	IVP_DOUBLE l1 = (-p->k[1] - sr ) * i2a;
	IVP_DOUBLE l2 = (-p->k[1] + sr ) * i2a;
	k[1] = l1;
	k[2] = l2;
    }
}


IVP_BOOL IVP_U_Point::is_parallel(const IVP_U_Point *v_in, IVP_DOUBLE eps)const {
    IVP_U_Point v1, v2, c;
    v1.set(this);
    v2.set(v_in);
    c.calc_cross_product(&v1, &v2);
    return( (IVP_BOOL)(c.quad_length() <= eps*eps * v1.quad_length() * v2.quad_length()) );
}


#if !defined(IVP_NO_DOUBLE)
IVP_DOUBLE IVP_U_Point::fast_real_length() const {
    IVP_DOUBLE ql = this->quad_length();
    return IVP_Fast_Math::sqrt(ql);
}
#endif

IVP_DOUBLE IVP_U_Float_Point::fast_real_length() const {
    IVP_DOUBLE ql = this->quad_length();
    return IVP_Fast_Math::sqrt(ql);
}

void IVP_U_Point::print(const char *comment){
    if(comment){
	printf("%s Point %f %f %f\n",comment, k[0],k[1],k[2]);
    }else{
	printf("Point %f %f %f\n", k[0],k[1],k[2]);
    }
}

void IVP_U_Float_Point::print(const char *comment)const{
    if(comment){
	printf("%s Point %f %f %f\n",comment, k[0],k[1],k[2]);
    }else{
	printf("Point %f %f %f\n", k[0],k[1],k[2]);
    }
}


void IVP_U_Point::line_min(const IVP_U_Point *p){
    int i;
    for (i=2;i>=0;i--){
	if (p->k[i] < k[i]) k[i] = p->k[i];
    }
}

void IVP_U_Point::line_max(const IVP_U_Point *p){
    int i;
    for (i=2;i>=0;i--){
	if (p->k[i] > k[i]) k[i] = p->k[i];
    }
}


IVP_RETURN_TYPE IVP_U_Point::set_crossing(IVP_U_Hesse *h0, IVP_U_Hesse *h1, IVP_U_Hesse *h2)
{
    IVP_RETURN_TYPE rval;
    
    IVP_U_Matrix lin_equ_matrix;
    lin_equ_matrix.init_rows4(h0, h1, h2,0);

    rval = lin_equ_matrix.real_invert();

    IVP_U_Point right_side;
    right_side.set(-h0->hesse_val, -h1->hesse_val, -h2->hesse_val);

    lin_equ_matrix.vmult3(&right_side, this);

    return(rval);
}

// rotate the point around origin
void IVP_U_Point::rotate(IVP_COORDINATE_INDEX axis, IVP_FLOAT angle) {
    int hp[5] = {0, 1, 2, 0, 1};
    int *p = &hp[axis];
    IVP_DOUBLE c = IVP_Inline_Math::cosd(angle);
    IVP_DOUBLE s = IVP_Inline_Math::sind(angle);
    IVP_DOUBLE x_new = c * k[p[1]] - s * k[p[2]];
    k[p[2]] = s * k[p[1]] + c * k[p[2]];
    k[p[1]] = x_new;
}

// rotate the point around origin
void IVP_U_Float_Point::rotate(IVP_COORDINATE_INDEX axis, IVP_FLOAT angle) {
    int hp[5] = {0, 1, 2, 0, 1};
    int *p = &hp[axis];
    IVP_DOUBLE c = IVP_Inline_Math::ivp_cosf(angle);
    IVP_DOUBLE s = IVP_Inline_Math::ivp_sinf(angle);
    IVP_DOUBLE x_new = c * k[p[1]] - s * k[p[2]];
    k[p[2]] = s * k[p[1]] + c * k[p[2]];
    k[p[1]] = x_new;
}



/****************************** Matrix Operations ******************************/

IVP_RETURN_TYPE IVP_U_Matrix3::get_angles(IVP_FLOAT *alpha, IVP_FLOAT *beta, IVP_FLOAT *gamma)
{
    // returns angles in alpha, beta and gamma
    // return value of 0 means error (while normizing)

    // third column of 'this' is my looking direction
    
    IVP_U_Matrix3 mat;
    mat = *this;

    if(!mat.orthonormize()){
	printf("No valid matrix in get_angles!\n");
	return IVP_FAULT;	// could not be normized
    }
    
    IVP_U_Point v;
    IVP_U_Matrix em, rot, mat_no_g, mat_no_g_no_b;
    em.init();
    
    // calc gamma
    v.set(mat.get_elem(0,2), 0.0f, mat.get_elem(2,2));
    if(!v.normize()){
	*gamma = 0.0f;
    }else{
	*gamma = IVP_Inline_Math::atan2d(v.k[0], v.k[2]);
    }
    em.rotate(IVP_INDEX_Y,*gamma, &rot);
    rot.mimult3(&mat, &mat_no_g); // no gamma

 
    // calc beta
    v.set(0.0f, mat_no_g.get_elem(1,2), mat_no_g.get_elem(2,2));
    if(!v.normize()){
	*beta = 0.0f;
    }else{
	*beta = -IVP_Inline_Math::atan2d(v.k[1], v.k[2]);
    }
    em.rotate(IVP_INDEX_X, *beta, &rot);
    rot.mimult3(&mat_no_g, &mat_no_g_no_b); // no gamma no beta
    
   // calc alpha
    v.set(mat_no_g_no_b.get_elem(0,0), mat_no_g_no_b.get_elem(1,0), 0.0f); // OS ?? or:  1 and 4
    if(!v.normize()){
	*alpha = 0.0f;
	printf("very strange: no alpha vec in get_angles!\n");
    }else{
	*alpha = (IVP_FLOAT)IVP_Inline_Math::atan2d(v.k[1], v.k[0]); // or vice versa...
    }
    em.rotate(IVP_INDEX_Z, *alpha, &rot);

    // rot.mimult4(&mat_no_g_no_b, &mat_equals_em);
    // mat_equals_em should be the ident matrix now!

    return IVP_OK;
}

void IVP_U_Matrix3::orthogonize(){
    /* 3x3 orthogonize */
    IVP_U_Point vz, vy, v2, v3;
    
    vz.set(get_elem(0,2), get_elem(1,2), get_elem(2,2)); // z-vector shall remain (= v1)
    vy.set(get_elem(0,1), get_elem(1,1), get_elem(2,1)); // y-vector

    v2.calc_cross_product(&vy, &vz);
    v3.calc_cross_product(&vz, &v2);

    // vz, v2, v3 are in a right system
    this->init_columns3(&v2,&v3,&vz);
    return;
}

IVP_RETURN_TYPE IVP_U_Matrix3::normize(){
    /* only 3x3, sets shift to zero */
    if (!rows[0].normize()) return IVP_FAULT;
    if (!rows[1].normize()) return IVP_FAULT;
    if (!rows[2].normize()) return IVP_FAULT;
    return IVP_OK;
}

IVP_RETURN_TYPE IVP_U_Matrix3::orthonormize()
{
    this->orthogonize();
    return this->normize();
}

/** Calculate one eigenvector for a given eigen value
  returns the degree of freedom of the eigenvector,
  the function assumes that there is at least one eigenvector !!!!
  */


int IVP_U_Matrix3::calc_eigen_vector(IVP_DOUBLE eigen_value, IVP_U_Point *eigen_vector_out){
    IVP_U_Matrix3 matrix = *this;
    IVP_DOUBLE m[3][3];		// row, column
    int col_index[3];		// the original index of a local col
    int row_index[3];		// the original index of a local row
    // search highest element in first column
    col_index[0] = 0;
    col_index[1] = 1;
    col_index[2] = 2;
    row_index[0] = 0;
    row_index[1] = 1;
    row_index[2] = 2;
    
    matrix.rows[0].k[0] -= eigen_value;
    matrix.rows[1].k[1] -= eigen_value;
    matrix.rows[2].k[2] -= eigen_value;
    
    {	// find maximum value in all values
	IVP_DOUBLE max = -1.0f;     // real maximum is always positiv
	int max_row = 0;
	int max_col= 0;
	
	for ( int row = 0;row<3;row++){
	    IVP_U_Point *current_row = &rows[row];
	    for ( int col = 0; col < 3; col++){
		IVP_DOUBLE v = current_row->k[col];
		v *= v;
		if (v > max) {
		    max = v;
		    max_col = col;
		    max_row = row;
		}
	    }
	}
    	row_index[0] = max_row;	// exchange columns to shift pivot element into m[0][0]
	row_index[max_row] = 0;

	col_index[0] = max_col;
	col_index[ max_col ] = 0;
	
	if (max < (P_DOUBLE_RES * P_DOUBLE_RES) ){	// 3 degree of freedom !!
	    eigen_vector_out->set(0,0,1);
	    return 3;
	}
    }

    {	// resort matrix
	for (int i=2;i>=0;i--){
	    IVP_U_Point *dest_row = &rows[i];
	    IVP_U_Point *source = &rows[row_index[i]];
	    dest_row->set(source);
	}
    }

    // get rid of first column values;
    {
	for (int r = 1; r<=2;r++){
	    IVP_DOUBLE f = m[r][0] / m[0][0];
	    m[r][1] -= f * m[0][1];
	    m[r][2] -= f * m[0][2];
	}
    }
    // get index of pivot element in 1 or 2rd row->flip rows
    {
	IVP_DOUBLE max = -1.0f;     // real maximum is always positiv
	int max_row=0,max_col=0;
    
	for ( int row = 1;row<3;row++){
	    IVP_DOUBLE *pm = &m[row][0];	// skip first row and column
	    for ( int col = 1; col < 3; col++){
		IVP_DOUBLE v = pm[col];
		v *= v;
		if (v > max) {
		    max = v;   max_col = col;    max_row = row;
		}
	    }
	}
	if (max_row != 1){	// switch rows  1 and 2
	    IVP_DOUBLE f;
	    f = m[1][1]; m[1][1] = m[2][1]; m[2][1] = f;
	    f = m[1][2]; m[1][2] = m[2][2]; m[2][2] = f;
	}
	if (max_col != 1){	// switch columns 1 and 2 and index pointer
	    IVP_DOUBLE h;
	    h = m[0][1]; m[0][1] = m[0][2]; m[0][2] = h;
	    h = m[1][1]; m[1][1] = m[1][2]; m[1][2] = h;
	    h = m[2][1]; m[2][1] = m[2][2]; m[2][2] = h;
	    int i;
	    i = col_index[2]; col_index[2] = col_index[1]; col_index[1] = i;
	}

    // check for 2 degrees of freedom !!
	if (max < (P_DOUBLE_RES * P_DOUBLE_RES) ){
	    eigen_vector_out->k[col_index[0]] = m[0][1] / m[0][0];
	    eigen_vector_out->k[col_index[1]] = 1.0f;
	    eigen_vector_out->k[col_index[2]] = 0.0f;
	    return 2;
	}
    }
    
    IVP_DOUBLE f2 = m[1][2]/m[1][1];
    
    // get rid of second column values;
    {
	m[2][2] -= f2 * m[2][1];		// this value should be zero, as we know we have an eigenvalue
    }
    // now we got an upper diagonal matrix,
    // set eigen_vector_out.k[index[2]] = 1.0
    eigen_vector_out->k[col_index[2]] = 1.0f;
    eigen_vector_out->k[col_index[1]] = -f2;
    eigen_vector_out->k[col_index[0]] = ( f2 * m[0][1] - m[0][2]) / m[0][0];
    return 1;
}



void IVP_U_Hesse::proj_on_plane(const IVP_U_Point *p, IVP_U_Point *result) const
{
    result->add_multiple(p, this, - get_dist(p)/quad_length());
                                  // div unnecessary, if hesse is normized
}

void IVP_U_Hesse::calc_hesse_val(const IVP_U_Point *p0){
	this->hesse_val= -this->dot_product(p0);
}

void IVP_U_Hesse::mult_hesse(IVP_DOUBLE factor){
    mult(factor);
    hesse_val *= factor;
}



void IVP_U_Hesse::calc_hesse(const IVP_U_Point *tp0,const IVP_U_Point *tp1,const IVP_U_Point *tp2)
{
	IVP_DOUBLE a0, a1, a2, b0, b1, b2;

	// calculate (non-normized) normal
	IVP_DOUBLE fp0 = tp0->k[0];
	IVP_DOUBLE fp1 = tp0->k[1];
	IVP_DOUBLE fp2 = tp0->k[2];
	a0 = tp1->k[0] - fp0;
	a1 = tp1->k[1] - fp1;
	a2 = tp1->k[2] - fp2;
	b0 = tp2->k[0] - fp0;
	b1 = tp2->k[1] - fp1;
	b2 = tp2->k[2] - fp2;

	IVP_DOUBLE c0 = b1*a2 - a1*b2;
	IVP_DOUBLE c1 = b2*a0 - a2*b0;
	IVP_DOUBLE c2 = b0*a1 - a0*b1;


	// calculate hesse-area
	this->k[0]=	c0;
	this->k[1]=	c1;
	this->k[2]=	c2;
	this->hesse_val=	-(this->k[0]*fp0 +
		this->k[1]*fp1 + this->k[2]*fp2);
};

void IVP_U_Hesse::calc_hesse(const IVP_U_Float_Point *tp0,
							 const IVP_U_Float_Point *tp1,
							 const IVP_U_Float_Point *tp2)
{
	IVP_DOUBLE a0, a1, a2, b0, b1, b2;

	// calculate (non-normized) normal
	IVP_DOUBLE fp0 = (IVP_DOUBLE)tp0->k[0];
	IVP_DOUBLE fp1 = (IVP_DOUBLE)tp0->k[1];
	IVP_DOUBLE fp2 = (IVP_DOUBLE)tp0->k[2];
	a0 = tp1->k[0] - fp0;
	a1 = tp1->k[1] - fp1;
	a2 = tp1->k[2] - fp2;
	b0 = tp2->k[0] - fp0;
	b1 = tp2->k[1] - fp1;
	b2 = tp2->k[2] - fp2;

	IVP_DOUBLE c0 = b1*a2 - a1*b2;
	IVP_DOUBLE c1 = b2*a0 - a2*b0;
	IVP_DOUBLE c2 = b0*a1 - a0*b1;


	// calculate hesse-area
	this->k[0]=	c0;
	this->k[1]=	c1;
	this->k[2]=	c2;
	this->hesse_val=	-(this->k[0]*fp0 +
		this->k[1]*fp1 + this->k[2]*fp2);
};


void IVP_U_Hesse::normize()
{
    IVP_DOUBLE l = 1.0f/this->real_length();
    this->mult(l);
    hesse_val *= l;
}

void IVP_U_Float_Hesse::mult_hesse(IVP_DOUBLE factor){
    mult(factor);
    hesse_val *= factor;
}


void IVP_U_Float_Hesse::proj_on_plane(const IVP_U_Float_Point *p, IVP_U_Float_Point *result) const
{
    result->add_multiple(p, this, - get_dist(p)/quad_length());
                                  // div unnecessary, if hesse is normized
}

void IVP_U_Float_Hesse::calc_hesse(const IVP_U_Float_Point *tp0,const IVP_U_Float_Point *tp1,const IVP_U_Float_Point *tp2)
{
	IVP_DOUBLE a0, a1, a2, b0, b1, b2;

	// calculate (non-normized) normal
	IVP_DOUBLE fp0 = tp0->k[0];
	IVP_DOUBLE fp1 = tp0->k[1];
	IVP_DOUBLE fp2 = tp0->k[2];
	a0 = tp1->k[0] - fp0;
	a1 = tp1->k[1] - fp1;
	a2 = tp1->k[2] - fp2;
	b0 = tp2->k[0] - fp0;
	b1 = tp2->k[1] - fp1;
	b2 = tp2->k[2] - fp2;

	IVP_DOUBLE c0 = b1*a2 - a1*b2;
	IVP_DOUBLE c1 = b2*a0 - a2*b0;
	IVP_DOUBLE c2 = b0*a1 - a0*b1;


	// calc hesse-plane
	this->k[0]=	(IVP_FLOAT)c0;
	this->k[1]=	(IVP_FLOAT)c1;
	this->k[2]=	(IVP_FLOAT)c2;
	this->hesse_val=(IVP_FLOAT)	-(this->k[0]*fp0 +
		this->k[1]*fp1 + this->k[2]*fp2);
};

void IVP_U_Float_Hesse::calc_hesse_val(const IVP_U_Float_Point *p0){
	this->hesse_val= -this->dot_product(p0);
}

void IVP_U_Float_Hesse::normize()
{
    IVP_DOUBLE l = 1.0f/this->real_length();
    this->mult(l);
    hesse_val *= l;
}




void IVP_U_Matrix::interpolate(const IVP_U_Matrix *m1, const IVP_U_Matrix *m2,
		    IVP_DOUBLE i_factor)
{
    // i_factor aus [0,1] -> this = interpolation between m1 & m2
    for( int r=0;r<3;r++){
	rows[r].set_interpolate( &m1->rows[r], &m2->rows[r], i_factor);
    }
    vv.set_interpolate( m1->get_position(), m2->get_position(), i_factor);
}



IVP_RETURN_TYPE IVP_U_Matrix::real_invert(IVP_DOUBLE epsilon)
{
    // real inversion using determinant algorithm
    
    IVP_U_Point r0; r0.inline_calc_cross_product( &rows[1], &rows[2] );
    IVP_U_Point r1; r1.inline_calc_cross_product( &rows[2], &rows[0] );
    IVP_U_Point r2; r2.inline_calc_cross_product( &rows[0], &rows[1] );

    IVP_DOUBLE D = rows[0].dot_product(&r0);	// main determinant
    
    if(IVP_Inline_Math::fabsd(D)< epsilon){
		return IVP_FAULT;  // cannot invert, may happen
    }    
    IVP_DOUBLE DI = 1.0f/D;
    r0.mult(DI);
    r1.mult(DI);
    r2.mult(DI);
    set_col(IVP_INDEX_X, &r0);
    set_col(IVP_INDEX_Y, &r1);
    set_col(IVP_INDEX_Z, &r2);
    
    IVP_U_Point p;
    this->vmult3(&this->vv, &p);
    vv.set_negative(&p);
    
    return IVP_OK;
}


IVP_DOUBLE IVP_U_Matrix3::get_determinante() const{
    IVP_U_Point r0; r0.inline_calc_cross_product( &rows[1], &rows[2] );
    IVP_DOUBLE D = rows[0].dot_product(&r0);	// main determinant
    return D;
}

IVP_RETURN_TYPE IVP_U_Matrix3::real_invert(IVP_DOUBLE epsilon)
{
    // real inversion using determinant algorithm
    
    IVP_U_Point r0; r0.inline_calc_cross_product( &rows[1], &rows[2] );
    IVP_U_Point r1; r1.inline_calc_cross_product( &rows[2], &rows[0] );
    IVP_U_Point r2; r2.inline_calc_cross_product( &rows[0], &rows[1] );

    IVP_DOUBLE D = rows[0].dot_product(&r0);	// main determinant
    
    if(IVP_Inline_Math::fabsd(D)< epsilon){
		return IVP_FAULT;  // cannot invert, may happen
    }    
    IVP_DOUBLE DI = 1.0f/D;
    r0.mult(DI);
    r1.mult(DI);
    r2.mult(DI);
    set_col(IVP_INDEX_X, &r0);
    set_col(IVP_INDEX_Y, &r1);
    set_col(IVP_INDEX_Z, &r2);
    
    return IVP_OK;
}

void IVP_U_Matrix::init(){
    P_MEM_CLEAR(this);
    set_elem(0,0,1.0f);
    set_elem(1,1,1.0f);
    set_elem(2,2,1.0f);
}

void IVP_U_Matrix3::init3(){
    P_MEM_CLEAR(this);
    set_elem(0,0,1.0f);
    set_elem(1,1,1.0f);
    set_elem(2,2,1.0f);
}

IVP_RETURN_TYPE IVP_U_Matrix:: real_invert(const IVP_U_Matrix *m, IVP_DOUBLE epsilon)
{
     // overloaded
    this->set_matrix(m);
    return this->real_invert(epsilon);
}


void IVP_U_Matrix::rotate(IVP_COORDINATE_INDEX axis, IVP_FLOAT angle, IVP_U_Matrix *m_out) {
    static int pm[5] = {1, 2, 0, 1, 2};
    const int *p = &pm[axis];

    IVP_DOUBLE SA = IVP_Inline_Math::sind(angle);
    IVP_DOUBLE CA = IVP_Inline_Math::cosd(angle);
    IVP_U_Matrix m_rot;
    P_MEM_CLEAR(&m_rot);
    m_rot.set_elem( p[2], p[2] ,1);
    m_rot.set_elem( p[0], p[0], CA );
    m_rot.set_elem( p[1], p[1], CA );
    m_rot.set_elem( p[0], p[1], -SA);
    m_rot.set_elem( p[1], p[0], SA);
    m_rot.mmult4(this, m_out);
}

void IVP_U_Matrix::rotate_invers(IVP_COORDINATE_INDEX axis, IVP_FLOAT angle, IVP_U_Matrix *m_out) {
    static const int pm[5] = {1, 2, 0, 1, 2};
    const int *p = &pm[axis];

    IVP_DOUBLE SA = IVP_Inline_Math::sind(angle);
    IVP_DOUBLE CA = IVP_Inline_Math::cosd(angle);
    IVP_U_Matrix m_rot;
    P_MEM_CLEAR(&m_rot);
    m_rot.set_elem(p[2], p[2], 1);
    m_rot.set_elem(p[0], p[0], CA);
    m_rot.set_elem(p[0], p[1], SA);
    m_rot.set_elem(p[1], p[0], -SA);
    m_rot.set_elem(p[1], p[1], CA);
    this->mi2mult4(&m_rot, m_out);
}

void IVP_U_Matrix3::init_rotated3(IVP_COORDINATE_INDEX axis, IVP_FLOAT angle) {
    static int pm[5] = {1, 2, 0, 1, 2};
    const int *p = &pm[axis];

    IVP_DOUBLE SA = IVP_Inline_Math::sind(angle);
    IVP_DOUBLE CA = IVP_Inline_Math::cosd(angle);
    P_MEM_CLEAR(this);
    this->set_elem( p[2], p[2] ,1.0f);
    this->set_elem( p[0], p[0], CA );
    this->set_elem( p[1], p[1], CA );
    this->set_elem( p[0], p[1], -SA);
    this->set_elem( p[1], p[0], SA);
}



void IVP_U_Matrix::init_rows4( const IVP_U_Point *v0, const IVP_U_Point *v1, const IVP_U_Point *v2,const IVP_U_Point *shift){
// initialize transponed from v0v1v2, vx is stored in rows
    rows[0].set(v0);
    rows[1].set(v1);
    rows[2].set(v2);

    if (shift){
	vv.set(shift);
    }else{
	vv.set_to_zero();
    }
}

// init orthornomized matrix given a Bs-axis in As coords
// result is a matrix m_Bs_f_As
void IVP_U_Matrix3::init_normized3_col(const IVP_U_Point *vp, IVP_COORDINATE_INDEX coordinate) {
    IVP_U_Point v0 = *vp;
    v0.normize();
    IVP_U_Point v2(v0.k[1], v0.k[2] - v0.k[0], -v0.k[1]);		// orthogonal vector
    if (v2.normize() == IVP_FAULT){
	v2.set(v0.k[2], -v0.k[2], v0.k[1] - v0.k[0] );
	v2.normize();
    }
    IVP_U_Point v1;    v1.inline_calc_cross_product(&v2, &v0);

    unsigned int p[5] = {0, 1, 2, 0, 1};
    unsigned int i0 = coordinate;
    unsigned int i1 = i0 + 1;
    unsigned int i2 = i1 + 1;

    set_col( IVP_COORDINATE_INDEX(p[i0]) , &v0);
    set_col( IVP_COORDINATE_INDEX(p[i1]) , &v1);
    set_col( IVP_COORDINATE_INDEX(p[i2]) , &v2);
}

// init orthornomized matrix given an As-axis in Bs coords
// result is a matrix m_Bs_f_As
void IVP_U_Matrix3::init_normized3_row(const IVP_U_Point *vp, IVP_COORDINATE_INDEX coordinate) {
    IVP_U_Point v0 = *vp;
    v0.normize();
    IVP_U_Point v2(v0.k[1], v0.k[2] - v0.k[0], -v0.k[1]);		// orthogonal vector
    if (v2.normize() == IVP_FAULT){
	v2.set(v0.k[2], -v0.k[2], v0.k[1] - v0.k[0] );
	v2.normize();
    }
    IVP_U_Point v1;   v1.inline_calc_cross_product(&v2, &v0);

    unsigned int p[5] = {0, 1, 2, 0, 1};
    unsigned int i0 = coordinate;
    unsigned int i1 = i0 + 1;
    unsigned int i2 = i1 + 1;

    rows[p[i0]] .set( &v0 );
    rows[p[i1]] .set( &v1 );
    rows[p[i2]] .set( &v2 );
}

// init orthornomized matrix given a Bs-axis and a Cs-axis in As coords
// result is a matrix m_Bs_f_As
void IVP_U_Matrix3::init_normized3_col(const IVP_U_Point *vb, IVP_COORDINATE_INDEX index_b, const IVP_U_Point *vc) {
    IVP_U_Point v0 = *vb; v0.normize();
    IVP_U_Point v2;	 v2.inline_calc_cross_product_and_normize(&v0, vc);
    IVP_U_Point v1;   v1.inline_calc_cross_product(&v2, &v0);

    unsigned int p[5] = {0, 1, 2, 0, 1};
    unsigned int i0 = index_b;
    unsigned int i1 = i0 + 1;
    unsigned int i2 = i1 + 1;

    set_col( IVP_COORDINATE_INDEX(p[i0]) , &v0);
    set_col( IVP_COORDINATE_INDEX(p[i1]) , &v1);
    set_col( IVP_COORDINATE_INDEX(p[i2]) , &v2);
}


// init orthornomized matrix given an As-axis in Bs coords
// result is a matrix m_Bs_f_As
void IVP_U_Matrix3::init_normized3_row(const IVP_U_Point *vb, IVP_COORDINATE_INDEX index_b, const IVP_U_Point *vc) {
    IVP_U_Point v0 = *vb; v0.normize();
    IVP_U_Point v2;    v2.inline_calc_cross_product_and_normize(&v0, vc);
    IVP_U_Point v1;    v1.inline_calc_cross_product(&v2, &v0);

    unsigned int p[5] = {0, 1, 2, 0, 1};
    unsigned int i0 = index_b;
    unsigned int i1 = i0 + 1;
    unsigned int i2 = i1 + 1;

    rows[p[i0]] .set( &v0);
    rows[p[i1]] .set( &v1);
    rows[p[i2]] .set( &v2);
}

void IVP_U_Matrix3::init_rows3(const IVP_U_Point *v0, const IVP_U_Point *v1, const IVP_U_Point *v2 ){
    rows[0].set(v0);
    rows[1].set(v1);
    rows[2].set(v2);
}

void IVP_U_Matrix3::init_columns3(const IVP_U_Point *v0, const IVP_U_Point *v1, const IVP_U_Point *v2 ){
    set_elem(0,0, v0->k[0]);	set_elem(1,0, v0->k[1]);	set_elem(2,0, v0->k[2]);
    set_elem(0,1, v1->k[0]);	set_elem(1,1, v1->k[1]);	set_elem(2,1, v1->k[2]);
    set_elem(0,2, v2->k[0]);	set_elem(1,2, v2->k[1]);	set_elem(2,2, v2->k[2]);
}

void IVP_U_Matrix::init_columns4(const IVP_U_Point *v0, const IVP_U_Point *v1, const IVP_U_Point *v2, const IVP_U_Point *shift ){
    set_elem(0,0, v0->k[0]);	set_elem(1,0, v0->k[1]);	set_elem(2,0, v0->k[2]);
    set_elem(0,1, v1->k[0]);	set_elem(1,1, v1->k[1]);	set_elem(2,1, v1->k[2]);
    set_elem(0,2, v2->k[0]);	set_elem(1,2, v2->k[1]);	set_elem(2,2, v2->k[2]);
    if (shift){
	vv.set(shift);
    }else{
	vv.set_to_zero();
    }
}

void IVP_U_Matrix::init_rot_multiple(const IVP_U_Point *angles, IVP_DOUBLE factor){// angles.k[0] = beta, [1] = gamma [2] = alpha,
    // mout = m_gamma * m_beta * m_alpha = m_k[1] * m_k[0] * m_k[2]
    IVP_DOUBLE x,y;
    if ( angles->k[0] ){
	x = IVP_Inline_Math::cosd( angles->k[0] * factor );
	y = IVP_Inline_Math::sind( angles->k[0] * factor);
    }else{
	x = 1.0f;
	y = 0.0f;
    }

    IVP_DOUBLE u,w;
    if ( angles->k[1] ){
	u = IVP_Inline_Math::cosd( angles->k[1] * factor );
	w = IVP_Inline_Math::sind( angles->k[1] * factor);
    }else{
	u = 1.0f;
	w = 0.0f;
    }

    IVP_DOUBLE c,s;
    if ( angles->k[2] ){
	c = IVP_Inline_Math::cosd( angles->k[2] * factor );
	s = IVP_Inline_Math::sind( angles->k[2] * factor);
    }else{
	c = 1.0f;
	s = 0.0f;
    }

    vv.set_to_zero();

    set_elem(0,0, u*c   + w*y*s);
    set_elem(0,1, w*y*c - u * s);
    set_elem(0,2, w * x);
    set_elem(1,0, x * s);
    set_elem(1,1, x * c);
    set_elem(1,2, -y);
    set_elem(2,0, y * u * s - w * c);
    set_elem(2,1, u * y * c + w * s);
    set_elem(2,2, u * x);
}


void IVP_U_Matrix::mmult4(const IVP_U_Matrix *mb, IVP_U_Matrix *m_out) const {
    inline_mmult4(mb,m_out);
}



void IVP_U_Matrix::mimult4(const IVP_U_Matrix *mb, IVP_U_Matrix *m_out) const {
    inline_mimult4(mb,m_out);
}


void IVP_U_Matrix3::mmult3(const IVP_U_Matrix3 *mb, IVP_U_Matrix3 *m_out) const {
    inline_mmult3(mb,m_out);
}

void IVP_U_Matrix3::mimult3(const IVP_U_Matrix3 *mb, IVP_U_Matrix3 *m_out) const {
    inline_mimult3(mb,m_out);
}

void IVP_U_Matrix::mi2mult4(const IVP_U_Matrix *mb, IVP_U_Matrix *m_out) const {
    /* m_out = this * mb^T */
    this->mi2mult3(mb,m_out);
    IVP_U_Point v_shift_korr;
    m_out->vmult3(&mb->vv,&v_shift_korr);
    m_out->vv.subtract(&this->vv, &v_shift_korr);
}

void IVP_U_Matrix3::mi2mult3(const IVP_U_Matrix3 *mb, IVP_U_Matrix3 *m_out) const {
    IVP_U_Point row[3];
    for (int r = 0;r<3;r++){
	mb->inline_vmult3(&rows[r], &row[r] );
    }
    m_out->rows[0].set(&row[0]);
    m_out->rows[1].set(&row[1]);
    m_out->rows[2].set(&row[2]);
}

void IVP_U_Matrix::transpose(){
	for (int i=1;i<3;i++) {
		for (int j=0;j<i;j++){
		    IVP_DOUBLE v = get_elem(i,j);
			set_elem( i,j, get_elem(j,i));
			set_elem( j,i,v);
		}
	}
	IVP_U_Point v_shift_korr;	
	this->vmult3(&this->vv,&v_shift_korr);
	vv.set_negative(&v_shift_korr);
};

void IVP_U_Matrix3::transpose3(){
	for (int i=1;i<3;i++) {
		for (int j=0;j<i;j++){
		    IVP_DOUBLE v = get_elem(i,j);
			set_elem( i,j, get_elem(j,i));
			set_elem( j,i,v);
		}
	}
};

void IVP_U_Matrix3::set_transpose3(const IVP_U_Matrix3 *in){
	set_elem( 0,0, in->get_elem(0,0));
	set_elem( 1,1, in->get_elem(1,1));
	set_elem( 2,2, in->get_elem(2,2));
	for (int i=1;i<3;i++) {
		for (int j=0;j<i;j++){
		    IVP_DOUBLE v = in->get_elem(i,j);
			set_elem( i,j, in->get_elem(j,i));
			set_elem( j,i,v);
		}
	}
};

void IVP_U_Matrix::set_transpose(const IVP_U_Matrix *in){
	set_elem( 0,0, in->get_elem(0,0));
	set_elem( 1,1, in->get_elem(1,1));
	set_elem( 2,2, in->get_elem(2,2));
	for (int i=1;i<3;i++) {
		for (int j=0;j<i;j++){
		    IVP_DOUBLE v = in->get_elem(i,j);
			set_elem( i,j, in->get_elem(j,i));
			set_elem( j,i,v);
		}
	}

	IVP_U_Point v_shift_korr;	
	this->vmult3(&in->vv,&v_shift_korr);
	vv.set_negative(&v_shift_korr);
};

#if !defined(IVP_NO_DOUBLE)
void IVP_U_Matrix::vimult4( const IVP_U_Point *p_in, IVP_U_Float_Point * p_out )const{
    inline_vimult4(p_in,p_out);
};
void IVP_U_Matrix::vimult4( const IVP_U_Point *p_in, IVP_U_Point * p_out )const{
    inline_vimult4(p_in,p_out);
};
#endif

void IVP_U_Matrix::vimult4( const IVP_U_Float_Point *p_in, IVP_U_Float_Point * p_out )const{
    inline_vimult4(p_in,p_out);
};


void IVP_U_Matrix::vmult4( const IVP_U_Float_Point *p_in, IVP_U_Float_Point * p_out )const{
    inline_vmult4(p_in,p_out);
};

#if !defined(IVP_NO_DOUBLE)
void IVP_U_Matrix::vmult4( const IVP_U_Point *p_in, IVP_U_Point * p_out )const{
    inline_vmult4(p_in,p_out);
};

void IVP_U_Matrix::vmult4( const IVP_U_Float_Point *p_in, IVP_U_Point * p_out )const{
    inline_vmult4(p_in,p_out);
};
#endif

void IVP_U_Matrix3::vmult3( const IVP_U_Float_Point *p_in, IVP_U_Float_Point * p_out )const{
    inline_vmult3(p_in,p_out);
};

#if !defined(IVP_NO_DOUBLE)
void IVP_U_Matrix3::vmult3( const IVP_U_Point *p_in, IVP_U_Point * p_out )const{
    inline_vmult3(p_in,p_out);
};

void IVP_U_Matrix3::vimult3( const IVP_U_Point *p_in, IVP_U_Point * p_out )const{
    inline_vimult3(p_in,p_out);
};
#endif

void IVP_U_Matrix3::vimult3( const IVP_U_Float_Point *p_in, IVP_U_Float_Point * p_out )const{
    inline_vimult3(p_in,p_out);
};


void IVP_U_Matrix::shift_ws( const IVP_U_Point *v_in ) {
    this->vv.add(v_in);
};



// recursion possible , works in object coords space
void IVP_U_Matrix::shift_os( const IVP_U_Point *v_in ) {
    IVP_U_Point v_out;
    vmult3(v_in,&v_out);
    this->vv.add(&v_out);
};



IVP_ERROR_STRING IVP_U_Matrix::write_to_file(FILE *fp, const char *key)
{
    // mark beginning
    if (key){
	fprintf(fp,"\t\t%s\n",key);
    }else{
	fprintf(fp,"\t\tMATRIX_START\n");
    }

    fprintf(fp,"\t\t\tMATRIX_ROT %g %g %g %g %g %g %g %g %g\n",
	    this->get_elem(0,0), this->get_elem(0,1), this->get_elem(0,2),
	    this->get_elem(1,0), this->get_elem(1,1), this->get_elem(1,2),
	    this->get_elem(2,0), this->get_elem(2,1), this->get_elem(2,2));

    fprintf(fp,"\t\t\tMATRIX_POS %g %g %g\n",
	    this->vv.k[0], this->vv.k[1], this->vv.k[2]);

    // mark end
    fprintf(fp,"\t\tMATRIX_END\n");
    return IVP_NO_ERROR;
}


void IVP_U_Matrix::print(const char *headline){
    if (headline) printf("%s\n",headline);
    printf("mm\t%g %g %g\n\t%g %g %g\n\t%g %g %g\n",
	   this->get_elem(0,0), this->get_elem(0,1), this->get_elem(0,2),
	   this->get_elem(1,0), this->get_elem(1,1), this->get_elem(1,2),
	   this->get_elem(2,0), this->get_elem(2,1), this->get_elem(2,2));

    printf("vv\t%g %g %g\n",
	   this->vv.k[0], this->vv.k[1], this->vv.k[2]);
}

IVP_ERROR_STRING IVP_U_Matrix::read_from_file(FILE *fp)
{
    char *cmd;
    while ((cmd = p_read_first_token(fp))){

	if( strcasecmp("MATRIX_START",cmd)==0 ){
	    continue;	// skip
	}

	if( strcasecmp("MATRIX_ROT",cmd)==0 ){
	    int i;
	    for (int r=0;r<3;r++){
		for(i=0; i<3; i++){
		    set_elem(r,i,get_float());
		}
	    }
	    continue;
	}

	if( strcasecmp("MATRIX_POS",cmd)==0 ){
	    this->vv.k[0] = get_float();
	    this->vv.k[1] = get_float();
	    this->vv.k[2] = get_float();
	    continue;
	}

	if( strcasecmp("MATRIX_END",cmd)==0 ){
	    break;
	}
	printf("Load IVP_U_Matrix: Unknown Command\n'%s'!\n",
	       cmd);
	CORE;
	return "ERROR in read Matrix";

    }
    return IVP_NO_ERROR;
}


IVP_DOUBLE IVP_U_Matrix3::quad_rot_distance_to(const IVP_U_Matrix3 *m2){
    
    IVP_DOUBLE sum =  this->rows[0].quad_distance_to(&m2->rows[0]) +
	this->rows[1].quad_distance_to(&m2->rows[1]) +
	this->rows[2].quad_distance_to(&m2->rows[2]);
    return sum;
}

IVP_DOUBLE IVP_U_Matrix::quad_distance_to(const IVP_U_Matrix *m2){
    return quad_rot_distance_to(m2) + vv.quad_distance_to(&m2->vv);
}

void IVP_U_Point::calc_an_orthogonal(const IVP_U_Point *ip)
{
    // change sign of biggest coordinate
    this->set(ip);
    
    int max_pos = 0;
    IVP_DOUBLE max = 0.0f;
    int i;
    for(i=2; i>=0; i--){
	IVP_DOUBLE h = IVP_Inline_Math::fabsd(k[i]);
	if(h>max){
	    max = h;
	    max_pos = i;
	}
    }
    k[max_pos] *= -1;
    IVP_DOUBLE h;
    int other_pos = max_pos-1;
    if(other_pos<0) other_pos = 2;
    h = k[max_pos];
    k[max_pos] = k[other_pos];
    k[other_pos] = h;

    this->calc_cross_product(this, ip);	// geht auf sich selber
}

