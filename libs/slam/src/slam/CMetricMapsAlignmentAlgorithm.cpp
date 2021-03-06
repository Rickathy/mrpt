/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          http://www.mrpt.org/                             |
   |                                                                           |
   | Copyright (c) 2005-2014, Individual contributors, see AUTHORS file        |
   | See: http://www.mrpt.org/Authors - All rights reserved.                   |
   | Released under BSD License. See details in http://www.mrpt.org/License    |
   +---------------------------------------------------------------------------+ */

#include <mrpt/slam.h>  // Precompiled header



#include <mrpt/slam/CMetricMapsAlignmentAlgorithm.h>

using namespace mrpt::slam; using namespace mrpt::utils; using namespace mrpt::poses;


/*---------------------------------------------------------------
					Align
  ---------------------------------------------------------------*/
CPosePDFPtr CMetricMapsAlignmentAlgorithm::Align(
    const CMetricMap		*m1,
    const CMetricMap		*m2,
    const CPose2D			&grossEst,
    float					*runningTime,
    void					*info )
{
	CPosePDFGaussian    posePDF(grossEst, CMatrixDouble33() );
	return AlignPDF(m1,m2,posePDF,runningTime,info);
}

/*---------------------------------------------------------------
					Align3D
  ---------------------------------------------------------------*/
CPose3DPDFPtr CMetricMapsAlignmentAlgorithm::Align3D(
    const CMetricMap		*m1,
    const CMetricMap		*m2,
    const CPose3D			&grossEst,
    float					*runningTime,
    void					*info )
{
	CPose3DPDFGaussian    posePDF;
	posePDF.mean = grossEst;
	return Align3DPDF(m1,m2,posePDF,runningTime,info);
}


