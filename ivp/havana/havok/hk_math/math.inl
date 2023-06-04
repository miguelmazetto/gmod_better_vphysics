#ifdef HK_PS2
#	include <hk_math/math_ps2.inl>
#else	//HK_PS2

#ifdef _WIN32
inline hk_double hk_Math::fabsd( hk_double r ) { return hk_double(::fabs(r)); }

inline hk_real hk_Math::sqrt( hk_real r) { return hk_real(::sqrt(r)); }
inline hk_real hk_Math::sqrt_inv(hk_real r) { return fast_sqrt_inv(r); }

inline hk_real hk_Math::fast_sqrt( hk_real r ) { return hk_real(::sqrt(r)); }

inline hk_real hk_Math::fabs( hk_real r) { return hk_real(::fabs(r)); }
inline hk_real hk_Math::tan( hk_real r) { return hk_real(::tan(r)); }
inline hk_real hk_Math::sin( hk_real r) { return hk_real(::sin(r)); }
inline hk_real hk_Math::cos( hk_real r) { return hk_real(::cos(r)); }
inline hk_real hk_Math::atan2( hk_real a, hk_real b)  { return hk_real(::atan2(a,b)); }
inline hk_real hk_Math::asin( hk_real r) { return hk_real(::asin(r)); }
inline hk_real hk_Math::acos( hk_real r) { return hk_real(::acos(r)); }
inline hk_real hk_Math::max( hk_real a, hk_real b) { return a>b ? a : b; }
inline hk_real hk_Math::min( hk_real a, hk_real b) { return a<b ? a : b; }

inline hk_real hk_Math::exp( hk_real e) { return hk_real(::exp(e)); }

inline hk_real hk_Math::floor( hk_real r ) { return hk_real(::floor(r)); }
inline hk_real hk_Math::ceil( hk_real r) { return hk_real(::ceil(r)); }
inline hk_real hk_Math::pow( hk_real r, hk_real p) { return hk_real(::pow(r,p)); }

#elif _LINUX || __APPLE__

namespace c_math
{
	extern "C"
	{
		double sqrt(double);
		double fabs(double);
		double sin(double);
		double cos(double);
		double tan(double);
		double atan2(double, double);
		double asin(double);
		double acos(double);
		double exp(double);
		double floor(double);
		double ceil(double);
		double pow(double, double);
	}
}

inline hk_double hk_Math::fabsd( hk_double r ) { return hk_double(c_math::fabs(r)); }

inline hk_real hk_Math::sqrt( hk_real r) { return hk_real(c_math::sqrt(r)); }
inline hk_real hk_Math::sqrt_inv( hk_real r) { return fast_sqrt_inv(r); }

inline hk_real hk_Math::fast_sqrt( hk_real r) { return hk_real(c_math::sqrt(r)); }

inline hk_real hk_Math::fabs( hk_real r) { return hk_real(c_math::fabs(r)); }
inline hk_real hk_Math::tan( hk_real r) { return hk_real(c_math::tan(r)); }
inline hk_real hk_Math::sin( hk_real r) { return hk_real(c_math::sin(r)); }
inline hk_real hk_Math::cos( hk_real r) { return hk_real(c_math::cos(r)); }
inline hk_real hk_Math::atan2( hk_real a, hk_real b)  { return hk_real(c_math::atan2(a,b)); }
inline hk_real hk_Math::asin( hk_real r) { return hk_real(c_math::asin(r)); }
inline hk_real hk_Math::acos( hk_real r) { return hk_real(c_math::acos(r)); }
inline hk_real hk_Math::max( hk_real a, hk_real b) { return a>b ? a : b; }
inline hk_real hk_Math::min( hk_real a, hk_real b) { return a<b ? a : b; }

inline hk_real hk_Math::exp( hk_real e) { return hk_real(c_math::exp(e)); }

inline hk_real hk_Math::floor( hk_real r ) { return hk_real(c_math::floor(r)); }
inline hk_real hk_Math::ceil( hk_real r) { return hk_real(c_math::ceil(r)); }
inline hk_real hk_Math::pow( hk_real r, hk_real p) { return hk_real(c_math::pow(r,p)); }
#endif

inline hk_real hk_Math::clamp( hk_real r, hk_real mn, hk_real mx)
{
	HK_ASSERT(mn<=mx);
	return ((r<mn)
				? mn
				: ((r>mx) ? mx : r));
}

inline int hk_Math::int_log2( hk_real ) { return 0; }


inline hk_real hk_Math::_rand01()
{
	// BSD rand function
	const unsigned a = 1103515245;
	const unsigned c = 12345;
	const unsigned m = unsigned(-1) >> 1;
	hk_random_seed = (a * hk_random_seed + c ) & m;
	return hk_real(hk_random_seed) / m;
}

inline hk_real hk_Math::fast_approx_atan2_normized( hk_real y, hk_real x)
{
	//const hk_real delta_at_pi_4 = HK_PI * 0.25f - hk_Math::sin(HK_PI * 0.25f);
	//const hk_real f = delta_at_pi_4 / hk_Math::sin(HK_PI * 0.25f) / hk_Math::sin(HK_PI * 0.25f)/ hk_Math::sin(HK_PI * 0.25f);
	const hk_real f = 0.2214414775f;
	hk_real r;
	if ( x > y ){
		if ( x > - y){
			r = y;
			r += y * y * y * f;
		}else{
			r = x - HK_PI_2;
			r += x * x * x * f;
		}
	}else{
		if ( x > - y){
			r = HK_PI_2 - x;
			r -= x * x * x * f;
		}else{
			if ( y > 0 ){
				r = HK_PI - y;
			}else{
				r = -y - HK_PI;
			}
			r -= y * y * y * f;
		}
	}
	return r;
}

inline hk_real hk_Math::fast_approx_atan2( hk_real y, hk_real x)
{
	//const hk_real delta_at_pi_4 = HK_PI * 0.25f - hk_Math::sin(HK_PI * 0.25f);
	//const hk_real f = delta_at_pi_4 / hk_Math::sin(HK_PI * 0.25f) / hk_Math::sin(HK_PI * 0.25f)/ hk_Math::sin(HK_PI * 0.25f);
	const hk_real f = 0.2214414775f;
	hk_real r;
	hk_real q = hk_Math::sqrt_inv( x * x + y * y );
	if ( x > y ){
		if ( x > - y){
			y *= q;
			r = y;
			r += y * y * y * f;
		}else{
			x *= q;
			r = x - HK_PI_2;
			r += x * x * x * f;
		}
	}else{
		if ( x > - y){
			x *= q;
			r = HK_PI_2 - x;
			r -= x * x * x * f;
		}else{
			y *= q;
			if ( y > 0 ){
				r = HK_PI - y;
			}else{
				r = -y - HK_PI;
			}
			r -= y * y * y * f;
		}
	}
	return r;
}

inline hk_real hk_Math::fast_sqrt_inv(hk_real y) {

	long i;
	hk_real x2;
	const hk_real threehalfs = 1.5F;

	x2 = y * 0.5F;
	i = *(long*)&y;                       // evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1);               // what the fuck?
	y = *(float*)&i;
	y = y * (threehalfs - (x2 * y * y));   // 1st iteration

	return y;
}

inline hk_double hk_Math::fast_sqrt_invd(hk_double y) {

	hk_double x2 = y * 0.5;
	long long i = *(long long*)&y;
	// The magic number is for doubles is from https://cs.uwaterloo.ca/~m32rober/rsqrt.pdf
	i = 0x5fe6eb50c7b537a9 - (i >> 1);
	y = *(hk_double*)&i;
	y = y * (1.5 - (x2 * y * y));   // 1st iteration
	//      y  = y * ( 1.5 - ( x2 * y * y ) );   // 2nd iteration, this can be removed
	return y;
}

//inline hk_nfloat hk_Math::fast_asin(hk_nfloat r) {
//	if(r >= 1.0f) return 1.57079633f;
//
//	r = r * 512 + 512;
//
//	int index = (int)r;
//	hk_nfloat decpart = r - index;
//	hk_nfloat nextfrac = 1.f - decpart;
//
//	return asintbl[index] * decpart + asintbl[index+1] * nextfrac;
//}
//
//inline hk_nfloat hk_Math::fast_acos(hk_nfloat r) { return 1.57079633 - asin(r); }

//inline hk_nfloat hk_Math::fast_sin(hk_nfloat r) {
//
//	if (r >= 1.0f) return 1.57079633f;
//
//	r = r * 512 + 512;
//
//	int index = (int)r;
//	hk_nfloat decpart = r - index;
//	hk_nfloat nextfrac = 1.f - decpart;
//
//	return asintbl[index] * decpart + asintbl[index + 1] * nextfrac;
//}

#endif// HK_PS2

