#ifndef Pad_Numeric_h__
#define Pad_Numeric_h__

typedef int pad_int;

#define pad_float_range_max 0.99999f;
#define numerror -1;

enum CommonDivisions
{
	div_disable = 1,
	div_trivial = 3,
	div_lowpoly_small = 6,
	div_lowpoly_large = 12,
	div_circle_smooth_start = 32,
	div_circle_smooth_good = 64,
	div_primitive_maximum = 1024,
	div_count = 8
};

enum DivisionsBevel
{
	div_bevel_lowpoly = 3,
	div_bevel_normal = 5,
	div_bevel_good = 8,
	div_bevel_count = 4
};
enum ContainerStartupCapacity
{
	capacity_minimum = 128,
	capacity_optimal = 1024,
	capacity_large_mesh = 1024 * 5,
	capacity_count = 3
};

enum class UnitsSystem
{
	none,
	metric,
	imperial
};
enum class MetricUnitSystem
{
	mm,
	cm,
	meter
};
enum class ImperialUnitSystem
{
	inch
};
#endif // Pad_Numeric_h__
