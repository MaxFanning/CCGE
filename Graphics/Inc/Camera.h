#ifndef INCLUDED_GRAPHICS_HEADER_H
#define INCLUDED_GRAPHICS_HEADER_H
#include "Common.h"

namespace CCGE {
namespace Graphics {

class Camera
{
public:
	Camera();
	~Camera();

	void SetPosition(const CMath::Vector3& position);
	void SetDirection(const CMath::Vector3& direction);
	void SetSetLookAt(const CMath::Vector3& target);

	void Walk(float distance);
	void Strafe(float distance);
	void Ride(float distance);

	void Yaw(float degree);
	void Pitch(float degree);

	void SetFOV(float fov);
	void SetNearPlane(float nearPlane);
	void SetFarPlane(float farPlane);

	CMath::Matrix GetViewMatrix();
	CMath::Matrix GetProjectionMatrix();

	// For homework
	// Finish the implementation of this class
	//		- Add getters and setters for the members
	//		- Plus anything you think will be convienent
	// Add a new project called "HelloCamera"
	//  - Setup a field of cubes so you have a fram of reference
	//  - Use the camera class to get the view/proj matrices
	//  - Use Input to control camera (WASD)

private:
	CMath::Vector3 mPosition;
	CMath::Vector3 mDirection;

	float mFOV;
	float mNearPlane;
	float mFarPlane;

};

}
}

#endif
