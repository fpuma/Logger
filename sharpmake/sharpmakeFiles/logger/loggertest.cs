namespace Puma
{
    [Sharpmake.Generate]
    class LoggerTest : Puma.Common.IMyApplication
    {
        public LoggerTest()
            : base("LoggerTest", @"loggertest")
        { }

        public override void ConfigureAll(Configuration conf, Sharpmake.Target target)
        {
            base.ConfigureAll(conf, target);

            conf.AddPublicDependency<Puma.Logger>(target);

            conf.Options.Add(Sharpmake.Options.Vc.General.TreatWarningsAsErrors.Enable);
        }
    }
}