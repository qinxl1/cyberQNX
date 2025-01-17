/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/*
* @Desc: Change History
* @Date: 2024-10-15
* @Version: 1.0.0
* @Feature List:
* -1. Put big data (PointCloud, Image) into another shared memory not the cyber message object
*     to accelerate transmission speed.
* 
*/

#pragma once

#include <memory>

#include "proto/lidar/pointcloud.pb.h"
#include "modules/tools/visualizer/renderable_object.h"

class QOpenGLShaderProgram;

class PointCloud : public RenderableObject {
 public:
  explicit PointCloud(int pointCount = 1, int vertex_element_count = 3,
                      const std::shared_ptr<QOpenGLShaderProgram>&
                          shaderProgram = NullRenderableObj);
  ~PointCloud(void);

  virtual GLenum GetPrimitiveType(void) const { return GL_POINTS; }

  /*bool FillData(
      const std::shared_ptr<const apollo::drivers::PointCloud>& pData);*/

  bool FillData(const std::vector<const apollo::drivers::PointCloud*>& point_cloud_arr);

 private:
  virtual bool FillVertexBuffer(GLfloat* vertexBuffer);

  GLfloat* buffer_;
};
