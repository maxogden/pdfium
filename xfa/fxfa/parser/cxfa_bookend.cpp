// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_bookend.h"

#include "fxjs/xfa/cjx_bookend.h"
#include "third_party/base/ptr_util.h"

namespace {

const CXFA_Node::AttributeData kBookendAttributeData[] = {
    {XFA_Attribute::Id, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Use, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Trailer, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Usehref, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Leader, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Unknown, XFA_AttributeType::Integer, nullptr}};

constexpr wchar_t kBookendName[] = L"bookend";

}  // namespace

CXFA_Bookend::CXFA_Bookend(CXFA_Document* doc, XFA_PacketType packet)
    : CXFA_Node(doc,
                packet,
                (XFA_XDPPACKET_Template | XFA_XDPPACKET_Form),
                XFA_ObjectType::Node,
                XFA_Element::Bookend,
                nullptr,
                kBookendAttributeData,
                kBookendName,
                pdfium::MakeUnique<CJX_Bookend>(this)) {}

CXFA_Bookend::~CXFA_Bookend() {}
