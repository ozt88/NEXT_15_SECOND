﻿#pragma warning disable 1591
//------------------------------------------------------------------------------
// <auto-generated>
//     이 코드는 도구를 사용하여 생성되었습니다.
//     런타임 버전:4.0.30319.18444
//
//     파일 내용을 변경하면 잘못된 동작이 발생할 수 있으며, 코드를 다시 생성하면
//     이러한 변경 내용이 손실됩니다.
// </auto-generated>
//------------------------------------------------------------------------------

namespace LinqTest
{
	using System.Data.Linq;
	using System.Data.Linq.Mapping;
	using System.Data;
	using System.Collections.Generic;
	using System.Reflection;
	using System.Linq;
	using System.Linq.Expressions;
	using System.ComponentModel;
	using System;
	
	
	[global::System.Data.Linq.Mapping.DatabaseAttribute(Name="Test")]
	public partial class DataClasses1DataContext : System.Data.Linq.DataContext
	{
		
		private static System.Data.Linq.Mapping.MappingSource mappingSource = new AttributeMappingSource();
		
    #region 확장성 메서드 정의
    partial void OnCreated();
    #endregion
		
		public DataClasses1DataContext() : 
				base(global::LinqTest.Properties.Settings.Default.TestConnectionString, mappingSource)
		{
			OnCreated();
		}
		
		public DataClasses1DataContext(string connection) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public DataClasses1DataContext(System.Data.IDbConnection connection) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public DataClasses1DataContext(string connection, System.Data.Linq.Mapping.MappingSource mappingSource) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public DataClasses1DataContext(System.Data.IDbConnection connection, System.Data.Linq.Mapping.MappingSource mappingSource) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public System.Data.Linq.Table<restorant> restorant
		{
			get
			{
				return this.GetTable<restorant>();
			}
		}
	}
	
	[global::System.Data.Linq.Mapping.TableAttribute(Name="dbo.restorant")]
	public partial class restorant
	{
		
		private System.Nullable<int> _no;
		
		private string _업종;
		
		private string _업태;
		
		private string _업소명;
		
		private string _소재지;
		
		private string _전화번호;
		
		private string _신고_허가_일자;
		
		public restorant()
		{
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_no", DbType="Int")]
		public System.Nullable<int> no
		{
			get
			{
				return this._no;
			}
			set
			{
				if ((this._no != value))
				{
					this._no = value;
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_업종", DbType="NVarChar(255)")]
		public string 업종
		{
			get
			{
				return this._업종;
			}
			set
			{
				if ((this._업종 != value))
				{
					this._업종 = value;
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_업태", DbType="NVarChar(255)")]
		public string 업태
		{
			get
			{
				return this._업태;
			}
			set
			{
				if ((this._업태 != value))
				{
					this._업태 = value;
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_업소명", DbType="NVarChar(255)")]
		public string 업소명
		{
			get
			{
				return this._업소명;
			}
			set
			{
				if ((this._업소명 != value))
				{
					this._업소명 = value;
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_소재지", DbType="NVarChar(255)")]
		public string 소재지
		{
			get
			{
				return this._소재지;
			}
			set
			{
				if ((this._소재지 != value))
				{
					this._소재지 = value;
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_전화번호", DbType="NVarChar(255)")]
		public string 전화번호
		{
			get
			{
				return this._전화번호;
			}
			set
			{
				if ((this._전화번호 != value))
				{
					this._전화번호 = value;
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Name="[신고(허가)일자]", Storage="_신고_허가_일자", DbType="NVarChar(255)")]
		public string 신고_허가_일자
		{
			get
			{
				return this._신고_허가_일자;
			}
			set
			{
				if ((this._신고_허가_일자 != value))
				{
					this._신고_허가_일자 = value;
				}
			}
		}
	}
}
#pragma warning restore 1591
