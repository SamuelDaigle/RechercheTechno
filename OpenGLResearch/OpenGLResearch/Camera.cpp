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
	direction = normalize(position - target);
	right = normalize(cross(up, direction));
	up = cross(direction, right);
}

void Camera::LookAt(vec3 _targetPosition)
{
	view = translate(translation) * lookAt(position, _targetPosition, vec3(0.0f, 1.0f, 0.0f));
}

mat4 Camera::GetViewMatrix()
{
	target = orientate3(rotation) * vec3(0,0,1);
	return lookAt(position, position + target, vec3(0.0f, 1.0f, 0.0f)) * translate(translation);
}