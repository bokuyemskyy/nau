#version 330 core
in vec3 vNormal;
in vec3 vPos;

out vec4 FragColor;

uniform vec3 uLightPos;
uniform vec3 uCameraPos;

void main() {
    vec3 N = normalize(vNormal);
    vec3 L = normalize(uLightPos - vPos);
    float diff = max(dot(N, L), 0.0);

    vec3 color = vec3(0.3, 0.6, 1.0);
    vec3 ambient = 0.1 * color;
    vec3 diffuse = diff * color;

    FragColor = vec4(ambient + diffuse, 1.0);
}
