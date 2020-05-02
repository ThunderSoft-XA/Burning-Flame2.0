//--------------------------------------------------------------------------------------
// File: Scene.cpp
// Desc: 
//
// Author:      QUALCOMM, Advanced Content Group - Snapdragon SDK
//
//               Copyright (c) 2013 QUALCOMM Technologies, Inc. 
//                         All Rights Reserved. 
//                      QUALCOMM Proprietary/GTDR
//--------------------------------------------------------------------------------------
#include <FrmPlatform.h>
#define GL_GLEXT_PROTOTYPES
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <FrmApplication.h>
#include <OpenGLES/FrmShader.h>
#include "Scene.h"

#include "particles.h"

//#include <GLFW/glfw3.h>

#include <time.h>

#if defined(__linux__)
#include <stdio.h>
#include <unistd.h>
#endif

#include <iostream>

#include <stdlib.h>




//GLuint       g_hShaderProgram;

//--------------------------------------------------------------------------------------
// Name: FrmCreateApplicationInstance()
// Desc: Global function to create the application instance
//--------------------------------------------------------------------------------------
CFrmApplication* FrmCreateApplicationInstance()
{
    return new CSample( "Burning Flame" );
}


//--------------------------------------------------------------------------------------
// Name: CSample()
// Desc: Constructor
//--------------------------------------------------------------------------------------
CSample::CSample( const CHAR* strName ) : CFrmApplication( strName )
{
    g_strWindowTitle = strName;
    m_nWidth   = 765;
    m_nHeight  = 480;
    g_fAspectRatio   = (FLOAT)m_nWidth / (FLOAT)m_nHeight;

    //g_hShaderProgram = 0;
    //g_VertexLoc = 0;
    //g_ColorLoc  = 1;
	
	m_pFont = NULL;
	m_FrameCount = 0;
	m_LastFPSDisplayTime = 0.0f;

	FrmLogMessage("ERROR: This is an OpenGL program\n");
}


//--------------------------------------------------------------------------------------
// Name: DrawScene()
// Desc: DrawScene
//--------------------------------------------------------------------------------------
void CSample::DrawScene(ParticleGenerator &particles, double time)
{
	FrmLogMessage("ERROR: enter DrawScene\n");

	glDisable( GL_DEPTH_TEST );

	GLfloat dt = 0.002f;
	GLfloat particle_scale = 150;

	particles.Update(dt);
	particles.Draw(particle_scale);
}


/*
//--------------------------------------------------------------------------------------
// Name: InitShaders()
// Desc: Initialize the shaders
//--------------------------------------------------------------------------------------
BOOL CSample::InitShaders()
{
	g_strVSProgram = 
    "#version 300 es                                                                             \n"
    "layout (location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>                    \n"
    "                                                                                            \n"
    "out vec2 TexCoords;                                                                         \n"
    "out vec4 ParticleColor;                                                                     \n"
    "                                                                                            \n"
    "uniform mat4 projection;                                                                    \n"
    "uniform vec2 offset;                                                                        \n"
    "uniform vec4 color;                                                                         \n"
    "uniform float scale;                                                                        \n"
    "                                                                                            \n"
    "void main()                                                                                 \n"
    "{                                                                                           \n"
        "TexCoords = vertex.zw;                                                                  \n"
        "ParticleColor = color; //vec4(0.999995, 0.999995, 0.5, 0.0);                            \n"
    "                                                                                            \n"
    "#ifdef ENABLE_VERTEX_OFFSET                                                                 \n"
        "gl_Position = projection * vec4(((vertex.xy - 0.5) * scale) + offset, 0.0, 1.0);        \n"
    "#else //!ENABLE_VERTEX_OFFSET                                                               \n"
        "gl_Position = projection * vec4((vertex.xy * scale) + offset, 0.0, 1.0);                \n"
    "#endif //ENABLE_VERTEX_OFFSET                                                               \n"
    "}																	                         \n";

    g_strFSProgram = 
    "#version 300 es                                                     \n"
    "in vec2 TexCoords;                                                  \n"
    "in vec4 ParticleColor;                                              \n"
    "                                                                    \n"
    "out vec4 color;                                                     \n"
    "                                                                    \n"
    "uniform sampler2D sprite;                                           \n"
    "                                                                    \n"
    "void main()                                                         \n"
    "{                                                                   \n"
    "#if 1                                                               \n"
	    "color = (texture(sprite, TexCoords) * ParticleColor);           \n"
    "#else                                                               \n"
        "color = ParticleColor;                                          \n"
    "#endif                                                              \n"
    "}																	 \n";
	
	// Create the shader program needed to render the texture
    {
		FrmLogMessage("Program: g_hShaderProgram   000");

        // Compile the shaders
        GLuint hVertexShader = glCreateShader( GL_VERTEX_SHADER );
        glShaderSource( hVertexShader, 1, &g_strVSProgram, NULL );
        glCompileShader( hVertexShader );

        GLuint hFragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
        glShaderSource( hFragmentShader, 1, &g_strFSProgram, NULL );
        glCompileShader( hFragmentShader );

        // Check for compile success
        GLint nCompileResult = 0;
	    glGetShaderiv(hFragmentShader, GL_COMPILE_STATUS, &nCompileResult);
	    if (!nCompileResult)
	    {
		    CHAR Log[1024];
		    GLint nLength;
		    glGetShaderInfoLog(hFragmentShader, 1024, &nLength, Log);
		    return FALSE;
	    }

        // Attach the individual shaders to the common shader program
        g_hShaderProgram = glCreateProgram();
        glAttachShader( g_hShaderProgram, hVertexShader );
        glAttachShader( g_hShaderProgram, hFragmentShader );

        // Init attributes BEFORE linking
        //glBindAttribLocation(g_hShaderProgram, g_VertexLoc, "g_vVertex");
        //glBindAttribLocation(g_hShaderProgram, g_ColorLoc, "g_vColor");

        // Link the vertex shader and fragment shader together
        glLinkProgram( g_hShaderProgram );

        // Check for link success
        GLint nLinkResult = 0;
	    glGetProgramiv(g_hShaderProgram, GL_LINK_STATUS, &nLinkResult);
	    if (!nLinkResult)
	    {
		    CHAR Log[1024];
		    GLint nLength;
		    glGetProgramInfoLog(g_hShaderProgram, 1024, &nLength, Log);
			FrmLogMessage("Shader compilation failed 000");
		    return FALSE;
	    }

        glDeleteShader( hVertexShader );
        glDeleteShader( hFragmentShader );
    }

    return TRUE;
}
*/

//--------------------------------------------------------------------------------------
// Name: Initialize()
// Desc: 
//--------------------------------------------------------------------------------------
BOOL CSample::Initialize()
{
	FrmLogMessage("ERROR: enter Initialize\n");

	// Create the font
	m_pFont = new CFrmFontGLES();
    if( FALSE == m_pFont->Create( "Samples/Fonts/Tuffy12.pak" ) )
	{
		FrmLogMessage("ERROR: create m_pFont failed\n");
        return FALSE;
	}
	
	// Load the packed resources
    CFrmPackedResourceGLES resource;
    if( FALSE == resource.LoadFromFile( "Samples/Textures/Logo.pak" ) )
	{
        return FALSE;
	}

    // Create the logo texture
    m_pLogoTexture = resource.GetTexture( "Logo" );

    // Setup the user interface
    if( FALSE == m_UserInterface.Initialize( m_pFont, g_strWindowTitle ) )
	{
        return FALSE;
	}

    m_UserInterface.AddOverlay( m_pLogoTexture->m_hTextureHandle, -5, -5, m_pLogoTexture->m_nWidth, m_pLogoTexture->m_nHeight );
	m_UserInterface.AddTextString( (char *)"Press \200 for Help", 1.0f, -1.0f );

	// Initialize the shaders
	/*if( FALSE == InitShaders() )
    {
        return FALSE;
    }
    */
	// Initialize
	srand(time(NULL));

	//GLuint amount = 1000;

#if 0
	GLuint scale = 3;
	particles = new ParticleGenerator(width * scale, height * scale, amount);
#else
	//particles = new ParticleGenerator(1000, 1000, amount);
    particles = ParticleGenerator();
#endif

    return TRUE;
}



//--------------------------------------------------------------------------------------
// Name: Resize()
// Desc: 
//--------------------------------------------------------------------------------------
BOOL CSample::Resize()
{
    particles = ParticleGenerator();
    return TRUE;
}


//--------------------------------------------------------------------------------------
// Name: Destroy()
// Desc: 
//--------------------------------------------------------------------------------------
VOID CSample::Destroy()
{
    //glDeleteProgram( g_hShaderProgram );
}


//--------------------------------------------------------------------------------------
// Name: Update()
// Desc: 
//--------------------------------------------------------------------------------------
VOID CSample::Update()
{
	FrmLogMessage("ERROR: enter Update\n");

	// Process input
	UINT32 nButtons;
	UINT32 nPressedButtons;
	FrmGetInput( &m_Input, &nButtons, &nPressedButtons );

	// Toggle user interface0
    if( nPressedButtons & INPUT_KEY_0 )
    {
		m_UserInterface.AdvanceState();
	}

    return;
}


//--------------------------------------------------------------------------------------
// Name: BuildInfoString()
// Desc: 
//--------------------------------------------------------------------------------------
void CSample::BuildInfoString(char *pBuffer, int iSize, float fFrameRate)
{
    FrmSprintf( pBuffer, iSize, "FPS: %0.2f", fFrameRate);
}

//--------------------------------------------------------------------------------------
// Name: FlameLogMsg_int()
// Desc: 
//--------------------------------------------------------------------------------------
void CSample::FlameLogMsg_int(int Msg)
{
	CHAR logMsg[80];
    FrmSprintf( logMsg, 80, "FlameLogMsg_int: %d", Msg);
	FrmLogMessage((char*) " %s\n", logMsg);
}

//--------------------------------------------------------------------------------------
// Name: FlameLogMsg_float()
// Desc: 
//--------------------------------------------------------------------------------------
void CSample::FlameLogMsg_float(float Msg)
{
	CHAR logMsg[80];
    FrmSprintf( logMsg, 80, "FlameLogMsg_float: %0.2f", Msg);
	FrmLogMessage((char*) " %s\n", logMsg);
}

//--------------------------------------------------------------------------------------
// Name: Render()
// Desc: 
//--------------------------------------------------------------------------------------
VOID CSample::Render()
{
	FrmLogMessage("ERROR: enter Render\n");

    // Display
	DrawScene(particles, FrmGetTime());

	// Update the timer
    m_Timer.MarkFrame();

	// Render the user interface
    m_UserInterface.Render( m_Timer.GetFrameRate() );
/*
	m_FrameCount++;
    FLOAT TimeNow = m_Timer.GetTime();
    FLOAT TimeDiff = TimeNow - m_LastFPSDisplayTime;
    //if(TimeDiff > 0.02f)
    {
        // Display the FPS
        float fFrameRate = (float)m_FrameCount / TimeDiff;
        CHAR strDisplay[80];
        BuildInfoString(strDisplay, 80, fFrameRate);
        FrmLogMessage((char*) " %s\n", strDisplay);
		m_pFont->SetScaleFactors( 0.8f, 0.8f );
        m_pFont->DrawText( (float)m_nHeight - 1.0f, (float)m_nWidth / 10.0f, FRMCOLOR_WHITE, strDisplay, FRM_FONT_RIGHT );
		//m_pFont->DrawText( (float)1.0f, (float)2.0f, FRMCOLOR_WHITE, strDisplay, FRM_FONT_RIGHT );

        m_FrameCount = 0;
        m_LastFPSDisplayTime = TimeNow;
    }
*/
}

