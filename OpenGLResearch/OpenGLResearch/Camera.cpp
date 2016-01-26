#include "Camera.h"

void Camera::Initialize()
{
	position = vec3(0, 0, -10);
	target = vec3(0, 0, 0);
	up = vec3(0, 1, 0);
}

void Camera::Destroy()
{

}

void Camera::Update()
{
	direction = normalize(position - target);
	right = normalize(cross(up, direction));
	up = cross(direction, right);

	LookAt(target);
}

void Camera::LookAt(vec3 _targetPosition)
{
	view = lookAt(position, _targetPosition, vec3(0.0f, 1.0f, 0.0f));
}