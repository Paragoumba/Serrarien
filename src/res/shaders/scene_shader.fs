#version 330 core

in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D texture1;
//uniform sampler2D texture2;

uniform float x;
uniform float y;

void main(){
    //FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.5);

//     float texX = TexCoord.x;
//     float texY = TexCoord.y;
//
//     if (sin(x) / 2 + 0.5 * 9 >= 5){
//
//         texX = -texX;
//
//     }
//
//     float flipY = sin(y) * 10;
//
//     if (flipY > 2 && flipY <= 7){
//
//         texY = -texY;
//
//     }
//
//     FragColor = texture(texture1, vec2(texX, texY));

    FragColor = texture(texture1, TexCoord);

}