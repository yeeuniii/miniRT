#ifndef STRUCT_H
# define STRUCT_H

# include "vector.h"

typedef struct s_color
{
	int	r;
	int	g;
	int	b;

}	t_color;

typedef struct s_ambient
{
	double	lighting_ratio; 	//주변조명 비율 0.0~1.0
	t_color	color;

}	t_ambient;

typedef struct s_camera
{
	t_point		origin;		//뷰포인트 시야점 좌표
	t_vector	direct;		//3D 정규화 방향 벡터 -1~1
	double		fov; 		// 수평시야각 0~180
	double		viewport_height;
	double		viewport_width;
	t_vector	x_direct_vector;
	t_vector	y_direct_vector;
	double		focal_length;
	t_point		left_bottom;
}	t_camera;

typedef struct s_light
{
	t_point		origin;		// 빛이 위치한 좌표
	double		bright_ratio;	// 빛의 밝기 비율 0.0~1.0
	t_color		color;

}	t_light;

typedef struct s_sphere
{
	t_point		center;	//구 중심 좌표
	double		diameter;	//구의 지름
	double		radius;
	t_color		color;

}	t_sphere;

typedef struct s_plane
{
	t_point		point;		//평면위의 한 점의 좌표
	t_vector	normal;	//3차원 정규화 법선 벡터 -1~1
	t_color		color;

}	t_plane;

typedef struct s_cylinder
{
	t_point		center;		//원기둥 중심점의 좌표
	t_vector	normal;	//3차원 정규화 원기둥 축 벡터 -1~1
	double		diameter;	//원기둥 지름
	double		radius;	//원기둥 지름
	double		height;		//원기둥 높이
	t_color		color;

}	t_cylinder;


#endif
