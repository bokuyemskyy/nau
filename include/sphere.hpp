#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

struct Vertex
{
    glm::vec3 pos;
    glm::vec3 normal;
};

void createSphere(std::vector<Vertex> &vertices, std::vector<unsigned int> &indices,
                  float radius, int sectors, int stacks)
{

    for (int i = 0; i <= stacks; ++i)
    {
        float v = (float)i / stacks;
        float phi = v * glm::pi<float>();

        for (int j = 0; j <= sectors; ++j)
        {
            float u = (float)j / sectors;
            float theta = u * glm::two_pi<float>();

            float x = radius * sin(phi) * cos(theta);
            float y = radius * cos(phi);
            float z = radius * sin(phi) * sin(theta);

            glm::vec3 pos = {x, y, z};
            glm::vec3 normal = glm::normalize(pos);

            vertices.push_back({pos, normal});
        }
    }

    for (int i = 0; i < stacks; ++i)
    {
        for (int j = 0; j < sectors; ++j)
        {
            int first = i * (sectors + 1) + j;
            int second = first + sectors + 1;

            indices.push_back(first);
            indices.push_back(second);
            indices.push_back(first + 1);

            indices.push_back(second);
            indices.push_back(second + 1);
            indices.push_back(first + 1);
        }
    }
}