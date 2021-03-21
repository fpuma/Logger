#include <logger/logger.h>
#include <logger/output/consolelogoutput.h>

#include <utils/formatstring.h>

int main( int argc, char* argv[] )
{
    puma::Logger logger;

    logger.addOutput<puma::ConsoleLogOutput>();

    puma::LogCategory logCategory = logger.registerCategory( "MyTestCategory" );

    for ( int i = 0; i < 2; ++i )
    {
        logger.info( logCategory, puma::formatString("Test log number: %d. User: %s", i, "fpuma").c_str() );
    }

    for ( int i = 0; i < 2; ++i )
    {
        logger.warning( logCategory, puma::formatString( "Test log number: %d. User: %s", i, "fpuma" ).c_str() );
    }

    for ( int i = 0; i < 2; ++i )
    {
        logger.error( logCategory, puma::formatString( "Test log number: %d. User: %s", i, "fpuma" ).c_str() );
    }

    logger.removeOutput<puma::ConsoleLogOutput>();

    logger.info( logCategory, "This text should not show because there are no outputs registered" );

    return 0;
}