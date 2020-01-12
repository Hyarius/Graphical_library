#include "jgl.h"

Matrix::Matrix(
	float a0, float a1, float a2, float a3,
	float b0, float b1, float b2, float b3,
	float c0, float c1, float c2, float c3,
	float d0, float d1, float d2, float d3)
{
	value[0][0] = a0;			value[0][1] = a1;				value[0][2] = a2;				value[0][3] = a3;
	value[1][0] = b0;			value[1][1] = b1;				value[1][2] = b2;				value[1][3] = b3;
	value[2][0] = c0;			value[2][1] = c1;				value[2][2] = c2;				value[2][3] = c3;
	value[3][0] = d0;			value[3][1] = d1;				value[3][2] = d2;				value[3][3] = d3;
}

Matrix::Matrix()
{
	value[0][0] = 1;			value[0][1] = 0;				value[0][2] = 0;				value[0][3] = 0;
	value[1][0] = 0;			value[1][1] = 1;				value[1][2] = 0;				value[1][3] = 0;
	value[2][0] = 0;			value[2][1] = 0;				value[2][2] = 1;				value[2][3] = 0;
	value[3][0] = 0;			value[3][1] = 0;				value[3][2] = 0;				value[3][3] = 1;
}

Matrix::Matrix(X_ROTATE, float angle)
{
	float		radian = degree_to_radius(angle);
	value[0][0] = 1.0f; 		value[0][1] = 0.0f;       		value[0][2] = 0.0f;				value[0][3] = 0;
	value[1][0] = 0.0f; 		value[1][1] = cos(radian); 		value[1][2] = sin(radian);		value[1][3] = 0;
	value[2][0] = 0.0f; 		value[2][1] = -sin(radian); 	value[2][2] = cos(radian);		value[2][3] = 0;
	value[3][0] = 0;			value[3][1] = 0;				value[3][2] = 0;				value[3][3] = 1;
}

Matrix::Matrix(Y_ROTATE, float angle)
{
	float		radian = degree_to_radius(angle);

	value[0][0] = cos(radian);	value[0][1] = 0.0f; 			value[0][2] = -sin(radian);		value[0][3] = 0;
	value[1][0] = 0.0f;      	value[1][1] = 1.0f; 			value[1][2] = 0.0f;				value[1][3] = 0;
	value[2][0] = sin(radian);	value[2][1] = 0.0f; 			value[2][2] = cos(radian);		value[2][3] = 0;
	value[3][0] = 0;			value[3][1] = 0;				value[3][2] = 0;				value[3][3] = 1;
}

Matrix::Matrix(Z_ROTATE, float angle)
{
	float		radian = degree_to_radius(angle);

	value[0][0] = cos(radian);	value[0][1] = sin(radian);		value[0][2] = 0.0f;				value[0][3] = 0;
	value[1][0] = -sin(radian);	value[1][1] = cos(radian);		value[1][2] = 0.0f;				value[1][3] = 0;
	value[2][0] = 0.0f; 		value[2][1] = 0.0f; 			value[2][2] = 1.0f;				value[2][3] = 0;
	value[3][0] = 0;			value[3][1] = 0;				value[3][2] = 0;				value[3][3] = 1;
}

Matrix::Matrix(ROTATION, float x, float y, float z)
{
	Matrix rotx = Matrix(X, x);
	Matrix roty = Matrix(Y, y);
	Matrix rotz = Matrix(Z, z);

	*this = rotx * roty * rotz;
}

Matrix::Matrix(TRANSLATION, float t_x, float t_y, float t_z)
{
	value[0][0] = 1.0f;			value[0][1] = 0.0f; 			value[0][2] = 0.0f;				value[0][3] = t_x;
	value[1][0] = 0.0f;			value[1][1] = 1.0f; 			value[1][2] = 0.0f;				value[1][3] = t_y;
	value[2][0] = 0.0f;			value[2][1] = 0.0f; 			value[2][2] = 1.0f;				value[2][3] = t_z;
	value[3][0] = 0;			value[3][1] = 0;				value[3][2] = 0;				value[3][3] = 1;
}

Matrix::Matrix(SCALE, float t_x, float t_y, float t_z)
{
	value[0][0] = t_x;			value[0][1] = 0.0f; 			value[0][2] = 0.0f;				value[0][3] = 0.0f;
	value[1][0] = 0.0f;			value[1][1] = t_y; 				value[1][2] = 0.0f;				value[1][3] = 0.0f;
	value[2][0] = 0.0f;			value[2][1] = 0.0f; 			value[2][2] = t_z;				value[2][3] = 0.0f;
	value[3][0] = 0;			value[3][1] = 0;				value[3][2] = 0;				value[3][3] = 1;
}

Matrix::Matrix(TRANSLATION, Vector3 delta)
{
	value[0][0] = 1.0f;			value[0][1] = 0.0f; 			value[0][2] = 0.0f;				value[0][3] = delta.x;
	value[1][0] = 0.0f;			value[1][1] = 1.0f; 			value[1][2] = 0.0f;				value[1][3] = delta.y;
	value[2][0] = 0.0f;			value[2][1] = 0.0f; 			value[2][2] = 1.0f;				value[2][3] = delta.z;
	value[3][0] = 0;			value[3][1] = 0;				value[3][2] = 0;				value[3][3] = 1;
}

Matrix::Matrix(SCALE, Vector3 delta)
{
	value[0][0] = delta.x;		value[0][1] = 0.0f; 			value[0][2] = 0.0f;				value[0][3] = 0.0f;
	value[1][0] = 0.0f;			value[1][1] = delta.y; 			value[1][2] = 0.0f;				value[1][3] = 0.0f;
	value[2][0] = 0.0f;			value[2][1] = 0.0f; 			value[2][2] = delta.z;			value[2][3] = 0.0f;
	value[3][0] = 0;			value[3][1] = 0;				value[3][2] = 0;				value[3][3] = 1;
}

Matrix			Matrix::operator * (Matrix p_matrix)
{
	int		i;
	int		j;
	Matrix	m = Matrix(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m.value[i][j] = (this->value[0][i] * p_matrix.value[j][0]) \
						+ (this->value[1][i] * p_matrix.value[j][1]) \
						+ (this->value[2][i] * p_matrix.value[j][2]) \
						+ (this->value[3][i] * p_matrix.value[j][3]);
			j++;
		}
		i++;
	}
	return (m);
}

Vector3		Matrix::operator * (Vector3 vertex)
{
	return (Vector3(
		value[0][0] * vertex.x + value[1][0] * vertex.y + value[2][0] * vertex.z + value[3][0] * value[3][3],
        value[0][1] * vertex.x + value[1][1] * vertex.y + value[2][1] * vertex.z + value[3][1] * value[3][3],
        value[0][2] * vertex.x + value[1][2] * vertex.y + value[2][2] * vertex.z + value[3][2] * value[3][3]
    ));
}

Vector4		Matrix::operator * (Vector4 vertex)
{
	return (Vector4(
		value[0][0] * vertex.x + value[1][0] * vertex.y + value[2][0] * vertex.z + value[3][0] * vertex.w,
        value[0][1] * vertex.x + value[1][1] * vertex.y + value[2][1] * vertex.z + value[3][1] * vertex.w,
        value[0][2] * vertex.x + value[1][2] * vertex.y + value[2][2] * vertex.z + value[3][2] * vertex.w,
        value[0][3] * vertex.x + value[1][3] * vertex.y + value[2][3] * vertex.z + value[3][3] * vertex.w
    ));
}
