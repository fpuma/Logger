#include <logger/logger.h>
#include <logger/output/consolelogoutput.h>

int main( int argc, char* argv[] )
{
    puma::Logger logger;

    logger.addOutput<puma::ConsoleLogOutput>();

    puma::LogCategory logCategory = logger.registerCategory( "MyTestCategory" );

    for ( int i = 0; i < 2; ++i )
    {
        logger.info( logCategory, "Test log number: %d. User: %s", i, "fpuma" );
    }

    for ( int i = 0; i < 2; ++i )
    {
        logger.warning( logCategory, "Test log number: %d. User: %s", i, "fpuma" );
    }

    for ( int i = 0; i < 2; ++i )
    {
        logger.error( logCategory, "Test log number: %d. User: %s", i, "fpuma" );
    }

    logger.removeOutput<puma::ConsoleLogOutput>();

    logger.info( logCategory, "This text should not show because there are no outputs registered" );

    return 0;
}