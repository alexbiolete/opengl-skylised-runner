#pragma once
#include <Component/SimpleScene.h>
#include <TextRenderer/TextRenderer.h>
#include <Component/Transform/Transform.h>
#include <Core/GPU/Mesh.h>

namespace EngineComponents
{
	class Camera;
}

class Background
{
public:
	glm::vec3 position;
};

class Gameplay
{
public:
	GLboolean first_person_camera;
	GLint lives, score;
	GLboolean lifeReposition, freeze;
};

class Sphere
{
public:
	glm::vec3 position, angle, rotationSpeed;
	GLfloat movementSpeed, radius;
	GLboolean debug, jumping, falling, mapFalling;
};

class Platform
{
public:
	glm::vec3 position;
	GLfloat radius = 0.1f;
	GLboolean has_obstacle, has_collectible, debug;
};

class Pyramid
{
public:
	glm::vec3 position;
	GLfloat scale;
};

class Obstacle
{
public:
	glm::vec3 position;
};

class Collectible
{
public:
	glm::vec3 position;
};

class Tema3 : public SimpleScene
{
public:
		Tema3();
		~Tema3();

		void Init() override;

		EngineComponents::Camera* camera;

private:
		void FrameStart() override;
		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, const glm::vec3& color = glm::vec3(1));
		void RenderTexturedMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix, Texture2D* texture1 = NULL, Texture2D* texture2 = NULL);

		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;

		// Draw the hud
		void drawHud();

		// Window resolution
		glm::ivec2 resolution;

		// Draw primitives mode
		GLenum polygonMode;

		// The text renderer
		TextRenderer* Text;

protected:
		GLboolean intersects(Sphere sphere, Platform platform);

		Mesh* mesh;
		glm::mat4 modelMatrix;
		glm::mat3 modelMatrix2D;

		glm::vec3 cameraPosition;
		glm::vec3 lightPosition;
		glm::vec3 lightDirection;

		GLuint materialShininess;
		GLfloat materialKd;
		GLfloat materialKs;
		GLfloat cutOff;

		std::unordered_map<std::string, Texture2D*> mapTextures;

		glm::vec3 color_white, color_blue, color_purple, color_red, color_yellow, color_orange, color_green, color_lightblue, color_gray, color_black;
		GLboolean collectible_trigger1, collectible_trigger2, obstacle_trigger1, obstacle_trigger2;
		GLfloat collectible_rotation = 0.0f;
};
