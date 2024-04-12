#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Shader.h"
#include "mentes/Shader.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    Shader ourShader("D:\\OpenGLTanulas\\OpenGLPracticeVol01\\shaders\\shader.vs", "D:\\OpenGLTanulas\\OpenGLPracticeVol01\\shaders\\shader.fs");

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);


        glfwSwapBuffers(window);
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        float vertices_first_triangle[] = {
         1.0f, 0.5f, 0.0f,
         0.0f, 0.5f, 0.0f,
         0.0f, -0.5f, 0.0f
        };

        float vertices_second_triangle[] = {
         -1.0f, 0.5f, 0.0f,
         0.0f, 0.5f, 0.0f,
         0.0f, -0.5f, 0.0f
        };

        unsigned int VBO;
        unsigned int VAO;
        
        unsigned int VBO2;
        unsigned int VAO2;



        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_first_triangle), vertices_first_triangle, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        ourShader.use();

        //ourShader.setFloat("offset", 0.5f);

        glBindVertexArray(VAO);

        glDrawArrays(GL_TRIANGLES, 0, 3);

  


        glGenVertexArrays(1, &VAO2);
        glGenBuffers(1, &VBO2);

        glBindVertexArray(VAO2);

        glBindBuffer(GL_ARRAY_BUFFER, VBO2);

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_second_triangle), vertices_second_triangle, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

        glEnableVertexAttribArray(0);

        glBindVertexArray(VAO2);

        glDrawArrays(GL_TRIANGLES, 0, 3);




    }
    glfwTerminate();

    

    return 0;
}


