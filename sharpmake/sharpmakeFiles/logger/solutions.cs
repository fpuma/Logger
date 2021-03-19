namespace Puma
{
    [Sharpmake.Generate]
    class LoggerSolution : Puma.Common.IMySolution
    {
        public LoggerSolution()
            : base("Logger")
        { }

        public override void ConfigureAll(Configuration conf, Sharpmake.Target target)
        {
            base.ConfigureAll(conf, target);
            conf.AddProject<Puma.Logger>(target);
            conf.AddProject<Puma.LoggerTest>(target);
        }
    }
}

