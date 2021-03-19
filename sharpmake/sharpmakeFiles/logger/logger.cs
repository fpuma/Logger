namespace Puma
{
    [Sharpmake.Generate]
    class Logger : Puma.Common.IMyLib
    {
        public Logger()
            : base("Logger", @"logger")
        { }

        public override void ConfigureAll(Configuration conf, Sharpmake.Target target)
        {
            base.ConfigureAll(conf, target);

            conf.AddPublicDependency<Puma.Utils>(target);

            conf.IncludePrivatePaths.Add(@"\private");
            conf.IncludePaths.Add(@"\public");

            conf.Options.Add(Sharpmake.Options.Vc.General.TreatWarningsAsErrors.Enable);
        }
    }
}