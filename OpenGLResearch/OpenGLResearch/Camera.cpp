#include "Camera.h"

void Camera::Initialize()
{
	rotation = vec3(0, 0, 0);
	translation = vec3(0, 0, 0);
	position = vec3(3, 0, -10);
	target = vec3(0, 0, 0);
	up = vec3(0, 1, 0);
	LookAt(target);
}

void Camera::Destroy()
{

}

void Camera::Update()
{
	target = orientate3(rotation) * vec3(0,0,1);
	direction = normalize(position - target);
	right = normalize(cross(up, direction));
	up = cross(direction, right);
}

void Camera::LookAt(vec3 _targetPosition)
{
	view = lookAt(position, position + _targetPosition, vec3(0.0f, 1.0f, 0.0f)) * translate(translation);
}

mat4 Camera::GetViewMatrix()
{
	LookAt(target);
	return view;
}