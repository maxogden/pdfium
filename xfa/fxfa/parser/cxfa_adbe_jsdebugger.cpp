// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_adbe_jsdebugger.h"

namespace {

const CXFA_Node::AttributeData kaDBE_JSDebuggerAttributeData[] = {
    {XFA_Attribute::Desc, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Lock, XFA_AttributeType::Integer, (void*)0},
    {XFA_Attribute::Unknown, XFA_AttributeType::Integer, nullptr}};

constexpr wchar_t kaDBE_JSDebuggerName[] = L"ADBE_JSDebugger";

}  // namespace

CXFA_aDBE_JSDebugger::CXFA_aDBE_JSDebugger(CXFA_Document* doc,
                                           XFA_PacketType packet)
    : CXFA_Node(doc,
                packet,
                XFA_XDPPACKET_Config,
                XFA_ObjectType::ContentNode,
                XFA_Element::ADBE_JSDebugger,
                nullptr,
                kaDBE_JSDebuggerAttributeData,
                kaDBE_JSDebuggerName) {}

CXFA_aDBE_JSDebugger::~CXFA_aDBE_JSDebugger() {}
