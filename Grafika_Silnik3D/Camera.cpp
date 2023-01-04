#include "Camera.h"
void Camera::UpdateCamera(unsigned int programShader)
{
    glUseProgram(programShader);
    view = glm::mat4(1.0f);
    view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    glUniformMatrix4fv(glGetUniformLocation(programShader, "view"), 1, GL_FALSE, &view[0][0]);
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
    glUniformMatrix4fv(glGetUniformLocation(programShader, "model"), 1, GL_FALSE, &model[0][0]);
}
void Camera::VerticalMove(bool isUp, float cameraSpeed)
{
    if(isUp)
        cameraPos += cameraSpeed * cameraFront;
    else
        cameraPos -= cameraSpeed * cameraFront;
}
void Camera::HorizontalMove(bool isRight,float cameraSpeed)
{
    if(isRight)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    else
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}