/******************************************************************************
* Copyright (c) 2013, Howard Butler (hobu.inc@gmail.com)
* Copyright (c) 2014-2015, Brad Chambers (brad.chambers@gmail.com)
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following
* conditions are met:
*
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in
*       the documentation and/or other materials provided
*       with the distribution.
*     * Neither the name of Hobu, Inc. or Flaxen Geo Consulting nor the
*       names of its contributors may be used to endorse or promote
*       products derived from this software without specific prior
*       written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
* OF SUCH DAMAGE.
****************************************************************************/

#pragma once

#include <pdal/Kernel.hpp>
#include <pdal/pdal_export.hpp>
#include <pdal/util/FileUtils.hpp>

#include <memory>
#include <string>

namespace pdal
{

class Options;
class Stage;

class PDAL_DLL GroundKernel : public Kernel
{
public:
    static void * create();
    static int32_t destroy(void *);
    std::string getName() const;
    int execute();

private:
    GroundKernel();
    void addSwitches();
    void validateSwitches();

    std::shared_ptr<Stage> makeReader(Options readerOptions);

    std::string m_inputFile;
    std::string m_outputFile;
    double m_maxWindowSize;
    double m_slope;
    double m_maxDistance;
    double m_initialDistance;
    double m_cellSize;
    bool m_classify;
    bool m_extract;
};

} // namespace pdal

