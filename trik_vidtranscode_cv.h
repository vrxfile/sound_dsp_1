#ifndef TRIK_VIDTRANSCODE_CV_H_
#define TRIK_VIDTRANSCODE_CV_H_

#include <xdc/std.h>
#include <ti/xdais/ialg.h>
#include <ti/xdais/dm/ividtranscode.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


/*
 *  ======== TRIK_VIDTRANSCODE_CV ========
 *  Our implementation of the IVIDTRANSCODE interface
 */
extern IVIDTRANSCODE_Fxns TRIK_VIDTRANSCODE_CV_FXNS;
extern IALG_Fxns TRIK_VIDTRANSCODE_CV_IALG;


typedef enum TRIK_VIDTRANSCODE_CV_VideoFormat
{
  TRIK_VIDTRANSCODE_CV_VIDEO_FORMAT_UNKNOWN = 0,
  TRIK_VIDTRANSCODE_CV_VIDEO_FORMAT_RGB888 = XDM_CUSTOMENUMBASE,
  TRIK_VIDTRANSCODE_CV_VIDEO_FORMAT_RGB565,
  TRIK_VIDTRANSCODE_CV_VIDEO_FORMAT_RGB565X,
  TRIK_VIDTRANSCODE_CV_VIDEO_FORMAT_YUV444,
  TRIK_VIDTRANSCODE_CV_VIDEO_FORMAT_YUV422
} TRIK_VIDTRANSCODE_CV_VideoFormat;


typedef struct TRIK_VIDTRANSCODE_CV_Params {
    IVIDTRANSCODE_Params	base;
} TRIK_VIDTRANSCODE_CV_Params;


typedef struct TRIK_VIDTRANSCODE_CV_DynamicParams {
    IVIDTRANSCODE_DynamicParams	base;

    XDAS_Int32			inputHeight;
    XDAS_Int32			inputWidth;
    XDAS_Int32			inputLineLength;

    XDAS_Int32			outputLineLength[IVIDTRANSCODE_MAXOUTSTREAMS];
} TRIK_VIDTRANSCODE_CV_DynamicParams;


typedef struct TRIK_VIDTRANSCODE_CV_InArgsAlg {
	//XDAS_Bool		inBoolParam;		// Input parameter
	XDAS_UInt8		volumeCoefficient;	// Volume coefficient (%)
	XDAS_UInt8		micDistance;		// Distance between microphones (cm)
	XDAS_UInt16		windowSize;			// Correlation window size
	XDAS_UInt16		numSamples;			// Number of sample to be processed
} TRIK_VIDTRANSCODE_CV_InArgsAlg;

typedef struct TRIK_VIDTRANSCODE_CV_InArgs {
    IVIDTRANSCODE_InArgs		base;
    TRIK_VIDTRANSCODE_CV_InArgsAlg	alg;
} TRIK_VIDTRANSCODE_CV_InArgs;


typedef struct TRIK_VIDTRANSCODE_CV_OutArgsAlg {
	XDAS_Int16		targetAngle;		// [-180...180]
	XDAS_UInt16		targetLeftVolume;	// [0...65535]
	XDAS_UInt16		targetRightVolume;	// [0...65535]
} TRIK_VIDTRANSCODE_CV_OutArgsAlg;

typedef struct TRIK_VIDTRANSCODE_CV_OutArgs {
    IVIDTRANSCODE_OutArgs		base;
    TRIK_VIDTRANSCODE_CV_OutArgsAlg	alg;
} TRIK_VIDTRANSCODE_CV_OutArgs;


#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // !TRIK_VIDTRANSCODE_CV_H_
