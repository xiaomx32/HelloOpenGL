#version 330 core

out vec4 fragColor;

void main() {
    vec2 center = vec2(400.0, 300.0);
    float dist = length(gl_FragCoord.xy - center);

    if (dist > 100) {
        discard;
    }

    fragColor = vec4(1.0, 1.0, 1.0, 1.0);
}
