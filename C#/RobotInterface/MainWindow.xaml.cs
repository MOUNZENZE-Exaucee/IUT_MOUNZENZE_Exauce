using System.Dynamic;
using System.IO;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;


namespace RobotInterface
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }


        private void BouttonEnvoyer_Click(object sender, RoutedEventArgs e)
        {
            Sendmesage();
            TextBoxReception.Text = TextBoxReception.Text + '\n';
            if (VarBoutton.Variable.boutonclor == 0) {
                VarBoutton.Variable.boutonclor = 1;
                BouttonEnvoyer.Background = Brushes.RoyalBlue;
            }
            else {
                if (VarBoutton.Variable.boutonclor == 1) {
                    VarBoutton.Variable.boutonclor = 0;
                    BouttonEnvoyer.Background = Brushes.Beige;
                }
            }
        }

        private void TexteBoxEmission_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter) {
                Sendmesage();
            }
        }
        public void Sendmesage()
        {
            TextBoxReception.Text = TextBoxReception.Text + "Reçu: " + TexteBoxEmission.Text;

            TexteBoxEmission.Text = null;
        }
    }

    public class VarBoutton
    {
        public struct Variable
        {
            public static int boutonclor = 0;
        }
    }
    

}

