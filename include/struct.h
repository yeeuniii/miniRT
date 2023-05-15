#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vector
{
	double x;
	double y;
	double z;

}	t_vec;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;

}	t_colors;

typedef struct s_ambient
{
	int			identifier; //식별자
	double		l_range; 	//주변조명 비율
	t_colors	colors;

}	t_ambient;

typedef struct s_camera
{
	int	identifier; 	//식별자
	t_vec	v_point;		//뷰포인트 시야점 좌표
	t_vec	o_vector_range;	//3D 정규화 방향 벡터
	int		fov; 			// 수평시야각
}	t_camera;

typedef struct s_light
{
	char		identifier; 	// 식별자
	t_vec		l_point;		// 빛이 위치한 좌표
	double		bright_range;	// 빛의 밝기 비율
	t_colors	colors;

}	t_light;

typedef struct s_sphere
{
	char		identifier;	//식별자
	t_vec		s_center;	//구 중심 좌표
	double		s_diameter;	//구의 지름
	t_colors	colors;

}	t_sphere;

typedef struct s_plane
{
	char		identifier;		//식별자
	t_vec		p_point;		//평면위의 한 점의 좌표
	t_vec		n_vector_range;	//3차원 정규화 법선 벡터
	t_colors	colors;

}	t_plane;

typedef struct s_cylinder
{
	char		identifier;	//식별자
	t_vec		center;		//원기둥 중심점의 좌표
	t_vec		vector_axis_range;	//3차원 정규화 원기둥 축 벡터
	double		diameter;	//원기둥 지름
	double		height;		//원기둥 높이
	t_colors	colors;

}	t_cylinder;


#endif