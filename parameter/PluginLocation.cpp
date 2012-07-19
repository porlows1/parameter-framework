/* 
 * INTEL CONFIDENTIAL
 * Copyright © 2011 Intel 
 * Corporation All Rights Reserved.
 * 
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its suppliers
 * or licensors. Title to the Material remains with Intel Corporation or its
 * suppliers and licensors. The Material contains trade secrets and proprietary
 * and confidential information of Intel or its suppliers and licensors. The
 * Material is protected by worldwide copyright and trade secret laws and
 * treaty provisions. No part of the Material may be used, copied, reproduced,
 * modified, published, uploaded, posted, transmitted, distributed, or
 * disclosed in any way without Intel’s prior express written permission.
 * 
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or delivery
 * of the Materials, either expressly, by implication, inducement, estoppel or
 * otherwise. Any license under such intellectual property rights must be
 * express and approved by Intel in writing.
 * 
 * CREATED: 2011-06-01
 * UPDATED: 2011-07-27
 */
#include "PluginLocation.h"

#define base CKindElement

CPluginLocation::CPluginLocation(const string& strName, const string& strKind) : base(strName, strKind)
{

}

const string& CPluginLocation::getFolder() const
{
    return _strFolder;
}

const list<string>& CPluginLocation::getPluginList() const
{
    return _pluginList;
}

bool CPluginLocation::fromXml(const CXmlElement &xmlElement, CXmlSerializingContext &serializingContext)
{
    (void) serializingContext;

    // Retrieve folder
    _strFolder = xmlElement.getAttributeString("Folder");

    // Get Info from children
    CXmlElement::CChildIterator childIterator(xmlElement);

    CXmlElement xmlPluginElement;

    while (childIterator.next(xmlPluginElement)) {

        // Fill Plugin List
        _pluginList.push_back(xmlPluginElement.getAttributeString("Name"));
    }

    // Don't dig
    return true;
}