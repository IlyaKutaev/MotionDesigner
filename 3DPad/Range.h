#ifndef Range_h__
#define Range_h__

#include <QObject>
#include <QtGlobal>
#include <Pad_Numeric.h>
#include <math.h>
#define PAD_SAFE

template <typename RangeType, typename RangeIntType>
class Range
{
public:
	RangeType LowerLimit = 0;
	RangeType UpperLimit = 1;
private:
	RangeType value = LowerLimit;
	RangeType range_size = UpperLimit - LowerLimit;
	RangeType percent_50 = LowerLimit + (range_size / 2);
	RangeType percent_75 = LowerLimit + (range_size * 0.75f);
	RangeType percent_95 = LowerLimit + (range_size * 0.95f);
	RangeType percent_33 = LowerLimit + (range_size * 0.33f);
	RangeType percent_25 = LowerLimit + (range_size * 0.25f);
	RangeType percent_10 = LowerLimit + (range_size * 0.1f);
public:
	Range() {}
	virtual ~Range() {}
public:
	inline RangeType percent50() const;
	inline RangeType percent75() const;
	inline RangeType percent95() const;
	inline RangeType percent33() const;
	inline RangeType percent25() const;
	inline RangeType percent10() const;
	inline RangeType Interpolate(RangeType percent);
	inline RangeType Interpolate(float percent0, 
		float percent1,
		float percent2,
		float percent3,
		float &out0, 
		float &out1,
		float &out2,
		float &out3
		);
};

template <typename RangeType, typename RangeIntType>
RangeType Range<RangeType, RangeIntType>::percent25() const
{
	return percent25;
}

template <typename RangeType, typename RangeIntType>
RangeType Range<RangeType, RangeIntType>::percent10() const
{
	return percent10;
}

template <typename RangeType, typename RangeIntType>
RangeType Range<RangeType, RangeIntType>::percent33() const
{
	return percent33;
}

template <typename RangeType, typename RangeIntType>
RangeType Range<RangeType, RangeIntType>::percent95() const
{
	return percent95;
}

template <typename RangeType, typename RangeIntType>
RangeType Range<RangeType, RangeIntType>::percent75() const
{
	return percent_75;
}

template <typename RangeType, typename RangeIntType>
RangeType Range<RangeType, RangeIntType>::percent50() const
{
	return percent_50;
}

template <typename RangeType, typename RangeIntType>
RangeType Range<RangeType, RangeIntType>::Interpolate(float percent0, float percent1 /*= 0*/, float percent2 /*= 0*/, float percent3, float &out0, float &out1, float &out2, float &out3/*= 0*/)
{
#pragma pack(push,16)
	union utype
	{
		__m128 r;
		float f[4];
	};
#pragma pack(pop)

	__m128 result0;
	{
		utype p0, p1;
		p0.f[0] = percent0;
		p0.f[1] = percent1;
		p0.f[2] = percent2;
		p0.f[3] = percent3;

		auto lr = static_cast<int>(range_size);
		p1.f[0] = lr;
		p1.f[1] = lr;
		p1.f[2] = lr;
		p1.f[3] = lr;

		result0 = _mm_mul_ps(p0.r, p1.r);
	}

	utype p2;
	int llim = static_cast<float>(LowerLimit);
	p2.f[0] = llim;
	p2.f[1] = llim;
	p2.f[2] = llim;
	p2.f[3] = llim;

	auto r2 = _mm_add_ps(result0, p2.r);

	&out0 = r2.f[0];
	&out1 = r2.f[1];
	&out2 = r2.f[2];
	&out3 = r2.f[3];
}

template <typename RangeType, typename RangeIntType>
RangeType Range<RangeType, RangeIntType>::Interpolate(RangeType percent)
{
#ifdef PAD_SAFE
	double under_one = nextafter(1, 0);
	if (percent >  under_one)
	{
		percent = pad_float_range_max;
	}

#endif
	range_size = UpperLimit - LowerLimit;
	value = LowerLimit + (range_size * percent);

	return value;
}



#endif // Range_h__
