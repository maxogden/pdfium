// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxgraphics/cfx_path.h"

#include "xfa/fxgraphics/cfx_path_generator.h"

CFX_Path::CFX_Path() {
  m_generator = nullptr;
}

FX_ERR CFX_Path::Create() {
  if (m_generator)
    return FX_ERR_Property_Invalid;

  m_generator = new CFX_PathGenerator;
  m_generator->Create();
  return FX_ERR_Succeeded;
}

CFX_Path::~CFX_Path() {
  delete m_generator;
}

FX_ERR CFX_Path::MoveTo(FX_FLOAT x, FX_FLOAT y) {
  if (!m_generator)
    return FX_ERR_Property_Invalid;
  m_generator->MoveTo(x, y);
  return FX_ERR_Succeeded;
}

FX_ERR CFX_Path::LineTo(FX_FLOAT x, FX_FLOAT y) {
  if (!m_generator)
    return FX_ERR_Property_Invalid;
  m_generator->LineTo(x, y);
  return FX_ERR_Succeeded;
}

FX_ERR CFX_Path::BezierTo(FX_FLOAT ctrlX1,
                          FX_FLOAT ctrlY1,
                          FX_FLOAT ctrlX2,
                          FX_FLOAT ctrlY2,
                          FX_FLOAT toX,
                          FX_FLOAT toY) {
  if (!m_generator)
    return FX_ERR_Property_Invalid;
  m_generator->BezierTo(ctrlX1, ctrlY1, ctrlX2, ctrlY2, toX, toY);
  return FX_ERR_Succeeded;
}

FX_ERR CFX_Path::ArcTo(FX_FLOAT left,
                       FX_FLOAT top,
                       FX_FLOAT width,
                       FX_FLOAT height,
                       FX_FLOAT startAngle,
                       FX_FLOAT sweepAngle) {
  if (!m_generator)
    return FX_ERR_Property_Invalid;
  m_generator->ArcTo(left + width / 2, top + height / 2, width / 2, height / 2,
                     startAngle, sweepAngle);
  return FX_ERR_Succeeded;
}

FX_ERR CFX_Path::Close() {
  if (!m_generator)
    return FX_ERR_Property_Invalid;
  m_generator->Close();
  return FX_ERR_Succeeded;
}

FX_ERR CFX_Path::AddLine(FX_FLOAT x1, FX_FLOAT y1, FX_FLOAT x2, FX_FLOAT y2) {
  if (!m_generator)
    return FX_ERR_Property_Invalid;
  m_generator->AddLine(x1, y1, x2, y2);
  return FX_ERR_Succeeded;
}

FX_ERR CFX_Path::AddBezier(FX_FLOAT startX,
                           FX_FLOAT startY,
                           FX_FLOAT ctrlX1,
                           FX_FLOAT ctrlY1,
                           FX_FLOAT ctrlX2,
                           FX_FLOAT ctrlY2,
                           FX_FLOAT endX,
                           FX_FLOAT endY) {
  if (!m_generator)
    return FX_ERR_Property_Invalid;
  m_generator->AddBezier(startX, startY, ctrlX1, ctrlY1, ctrlX2, ctrlY2, endX,
                         endY);
  return FX_ERR_Succeeded;
}

FX_ERR CFX_Path::AddRectangle(FX_FLOAT left,
                              FX_FLOAT top,
                              FX_FLOAT width,
                              FX_FLOAT height) {
  if (!m_generator)
    return FX_ERR_Property_Invalid;
  m_generator->AddRectangle(left, top, left + width, top + height);
  return FX_ERR_Succeeded;
}

FX_ERR CFX_Path::AddEllipse(FX_FLOAT left,
                            FX_FLOAT top,
                            FX_FLOAT width,
                            FX_FLOAT height) {
  if (!m_generator)
    return FX_ERR_Property_Invalid;
  m_generator->AddEllipse(left + width / 2, top + height / 2, width / 2,
                          height / 2);
  return FX_ERR_Succeeded;
}

FX_ERR CFX_Path::AddEllipse(const CFX_RectF& rect) {
  if (!m_generator)
    return FX_ERR_Property_Invalid;
  m_generator->AddEllipse(rect.left + rect.Width() / 2,
                          rect.top + rect.Height() / 2, rect.Width() / 2,
                          rect.Height() / 2);
  return FX_ERR_Succeeded;
}

FX_ERR CFX_Path::AddArc(FX_FLOAT left,
                        FX_FLOAT top,
                        FX_FLOAT width,
                        FX_FLOAT height,
                        FX_FLOAT startAngle,
                        FX_FLOAT sweepAngle) {
  if (!m_generator)
    return FX_ERR_Property_Invalid;
  m_generator->AddArc(left + width / 2, top + height / 2, width / 2, height / 2,
                      startAngle, sweepAngle);
  return FX_ERR_Succeeded;
}

FX_ERR CFX_Path::AddPie(FX_FLOAT left,
                        FX_FLOAT top,
                        FX_FLOAT width,
                        FX_FLOAT height,
                        FX_FLOAT startAngle,
                        FX_FLOAT sweepAngle) {
  if (!m_generator)
    return FX_ERR_Property_Invalid;
  m_generator->AddPie(left + width / 2, top + height / 2, width / 2, height / 2,
                      startAngle, sweepAngle);
  return FX_ERR_Succeeded;
}

FX_ERR CFX_Path::AddSubpath(CFX_Path* path) {
  if (!m_generator)
    return FX_ERR_Property_Invalid;
  m_generator->AddPathData(path->GetPathData());
  return FX_ERR_Succeeded;
}

FX_ERR CFX_Path::Clear() {
  if (!m_generator)
    return FX_ERR_Property_Invalid;
  m_generator->GetPathData()->SetPointCount(0);
  return FX_ERR_Succeeded;
}

FX_BOOL CFX_Path::IsEmpty() {
  if (!m_generator)
    return FX_ERR_Property_Invalid;
  if (m_generator->GetPathData()->GetPointCount() == 0) {
    return TRUE;
  }
  return FALSE;
}

CFX_PathData* CFX_Path::GetPathData() {
  if (!m_generator)
    return nullptr;
  return m_generator->GetPathData();
}
