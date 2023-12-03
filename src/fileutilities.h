//
// Created by epuls on 12/2/2023.
//


#ifndef VULKANTUTORIAL_FILEUTILITIES_H
#define VULKANTUTORIAL_FILEUTILITIES_H

#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <fstream>
#include <sstream>
#include <iostream>


// https://stackoverflow.com/questions/21120699/c-obj-file-parser
// heavily referenced above ^ work on expanding for more advanced OBJ features.
// Used primarily for learning purposes. Integrate assimp for more effective asset imports

bool loadOBJ (const char * path,
              std::vector<glm::vec3> &out_vertices,
              std::vector<glm::vec2> &out_uvs,
              std::vector<glm::vec3> &out_normals,
              std::vector<glm::vec3> &out_faces_1,
              std::vector<glm::vec3> &out_faces_2){

    std::ifstream file(path);
    if(file.fail()){
        std::cerr << "failed to open file!"; //probably build error handler class instead of calling here
        return false;
    }


    std::string line;
    while (std::getline(file, line))
    {
        std::string lineStart = line.substr(0,2);
        if(lineStart == "v ")
        { //parse vertices
            std::istringstream v(line.substr(2));
            double x,y,z;
            v>>x; v>>y; v>>z;
            glm::vec3 vert(x, y, z);
            out_vertices.push_back(vert);
        }
        else if (lineStart == "vt")
        { //parse texcoords
            std::istringstream vt(line.substr(3));
            int u, v;
            vt>>u; vt>>v;
            glm::vec2 tex(u,v);
            out_uvs.push_back(tex);
        }
        else if (lineStart == "vn")
        {
            std::istringstream vn(line.substr(3));
            double x, y, z;
            vn>>x; vn>>y; vn>>z;
            glm::vec3 norm(x,y,z);
            out_normals.push_back(norm);
        }
        else if (lineStart == "f ")
        { //parse faces
            std::istringstream f(line.substr(2));
            int a,b,c; //mesh indices
            int A,B,C; //texture indices

            const char* chh=line.c_str();
            sscanf (chh, "f %i/%i %i/%i %i/%i",&a,&A,&b,&B,&c,&C); //here it read the line start with f and store the corresponding values in the variables

            a--;b--;c--;
            A--;B--;C--;

            //faceIndex.push_back(a);textureIndex.push_back(A);
            //faceIndex.push_back(b);textureIndex.push_back(B);
            //faceIndex.push_back(c);textureIndex.push_back(C);
        }
    }

    /*
    //the mesh data is finally calculated here
    for(unsigned int i=0;i<faceIndex.size();i++)
    {
        glm::vec3 meshData;
        glm::vec2 texData;
        meshData=glm::vec3(vertices[faceIndex[i]].x,vertices[faceIndex[i]].y,vertices[faceIndex[i]].z);
        texData=glm::vec2(texture[textureIndex[i]].x,texture[textureIndex[i]].y);
        meshVertices.push_back(meshData);
        texCoord.push_back(texData);
    }
     */

    return true;
}





#endif //VULKANTUTORIAL_FILEUTILITIES_H
