#include "Camera.h"

void Camera::Initialize()
{
	rotation = vec3(0, 0, 0);
	position = vec3(0, 0, 0);
	target = vec3(0, 0, 0);
	up = vec3(0, 1, 0);
	LookAt(target);
}

void Camera::Destroy()
{

}

void Camera::Update()
{
	target = orientate3(rotation) * vec3(0, 0, 1);
	forward = normalize(target);
	right = normalize(cross(up, forward));

	LookAt(forward);
}

void Camera::LookAt(vec3 _targetPosition)
{
	view = lookAt(vec3(0, 0, 0), _targetPosition, vec3(0.0f, 1.0f, 0.0f)) * translate(position);
}

mat4 Camera::GetViewMatrix()
{
	return view;
}