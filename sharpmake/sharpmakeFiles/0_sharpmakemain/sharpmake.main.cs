using System.IO;

[module: Sharpmake.Include(@"..\base\*")]

[module: Sharpmake.Include(@"..\extern\*")]
[module: Sharpmake.Include(@"..\logger\*")]

public static class SharpmakeMainClass
{
    [Sharpmake.Main]
    public static void SharpmakeMain(Sharpmake.Arguments sharpmakeArgs)
    {
        sharpmakeArgs.Generate<Puma.LoggerSolution>();
    }
}

